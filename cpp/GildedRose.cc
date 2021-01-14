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

    for (auto &it : items) {
        --it.sellIn;
        if (it.name == AGEDBRIE) {
            refreshQuality(it.quality);
            if (it.sellIn < 0) {
                refreshQuality(it.quality);
            }
        } else if (it.name == BACKSTAGEPASS) {
            refreshQuality(it.quality);

            if (it.sellIn < 5) {
                ++it.quality;
            }
            if (it.sellIn < 10) {
                ++it.quality;
            }
            if (it.sellIn < 0) {
                it.quality = 0;
            }
        } else if (it.name == SULFURAS) {
            it.sellIn++;
            refreshQuality(it.quality);
        }

        else  // Every other item
        {
            if (it.quality > 0) {
                --it.quality;
            }
            if (it.sellIn < 0) {
                if (it.quality > 0) {
                    --it.quality;
                }
            }
        }
    }
}
