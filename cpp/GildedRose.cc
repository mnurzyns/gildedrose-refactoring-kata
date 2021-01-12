#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const& items)
    : items(items) {
}

GildedRose::GildedRose(::std::vector<Item>&& items)
    : items(::std::move(items)) {
}

// jeżeli quality < 50 to dodaj quality
int refreshQuality(int& itquality) {
    if (itquality < 50)
        itquality++;
    return itquality;
}

void GildedRose::updateQuality() {
    const char* AGEDBRIE = "Aged Brie";
    const char* BACKSTAGEPASS = "Backstage passes to a TAFKAL80ETC concert";
    const char* SULFURAS = "Sulfuras, Hand of Ragnaros";

    for (int i = 0; i < items.size(); i++) {
        --items[i].sellIn;
        if (items[i].name == AGEDBRIE) {
            refreshQuality(items[i].quality);
            if (items[i].sellIn < 0) {
                refreshQuality(items[i].quality);
            }
        } else if (items[i].name == BACKSTAGEPASS) {
            refreshQuality(items[i].quality);

            if (items[i].sellIn < 5) {
                ++items[i].quality;
            }
            if (items[i].sellIn < 10) {
                ++items[i].quality;
            }
            if (items[i].sellIn < 0) {
                items[i].quality = 0;
            }
        } else if (items[i].name == SULFURAS) {
            items[i].sellIn++;
            refreshQuality(items[i].quality);
        }

        else  // Every other item
        {
            if (items[i].quality > 0) {
                --items[i].quality;
            }
            if (items[i].sellIn < 0) {
                if (items[i].quality > 0) {
                    --items[i].quality;
                }
            }
        }
    }
}
