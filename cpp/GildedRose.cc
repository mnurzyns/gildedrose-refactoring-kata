#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items)
{
}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items))
{
}

auto isFresh = [](int &quality) { (quality < 50) ? quality++ : quality; };



void GildedRose::updateQuality()
{
    const std::string aged = "Aged Brie";
    const std::string sulfuras = "Sulfuras, Hand of Ragnaros";
    const std::string backstage = "Backstage passes to a TAFKAL80ETC concert";

    for (auto &it : items)
    {
        --it.sellIn;
        
        if (it.name == aged)
        {

            isFresh(it.quality);

            if (it.sellIn < 0)
            {
                isFresh(it.quality);
            }

            continue;
        }
        
        if (it.name == sulfuras)
        {
            ++it.sellIn;
            isFresh(it.quality);
            continue;
        }
        
        if (it.name == backstage)
        {

            if (it.sellIn < 0)
            {
                it.quality = 0;
            }
            else if (it.sellIn < 5)
            {
                it.quality += 3;
            }
            else if (it.sellIn < 10)
            {
                it.quality += 2;
            }
            else
            {
                isFresh(it.quality);
            }
            continue;
        }

        if (it.quality > 0)
        {
            --it.quality;

            if (it.sellIn < 0)
            {
                --it.quality;
            }
        }
    }
}
