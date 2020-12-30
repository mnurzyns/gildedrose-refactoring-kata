#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    using std::string;
    const string brie = "Aged Brie";
    const string concert = "Backstage passes to a TAFKAL80ETC concert";
    const string sulfuras = "Sulfuras, Hand of Ragnaros";
    for (auto elem : items)
    {
        if (elem.name != brie && elem.name != concert && elem.name != sulfuras && elem.quality > 0)
            --elem.quality;
        else if (elem.quality < 50)
        {
            ++elem.quality;

            if (elem.name == concert && elem.sellIn < 6) ++elem.quality;
            if (elem.name == concert && elem.sellIn < 11) ++elem.quality;
        }

        if (elem.name != sulfuras) --elem.sellIn;

        if (elem.sellIn < 0)
        {
            if (elem.name != brie && elem.name != concert && elem.name != sulfuras && elem.quality > 0) --elem.quality;
            else if (elem.name != brie  && (elem.name == concert || elem.name == sulfuras || elem.quality <= 0)) elem.quality = 0;
            else if (elem.quality < 50) ++elem.quality;
        }
    }
}