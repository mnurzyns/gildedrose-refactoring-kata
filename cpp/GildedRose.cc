#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items)
{
}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items))
{
}

void GildedRose::updateQuality()
{
    const std::string aged = "Aged Brie";
    const std::string sulfuras = "Sulfuras, Hand of Ragnaros";
    const std::string backstage = "Backstage passes to a TAFKAL80ETC concert";

    for (auto &it : items)
    {

        if (it.name == aged)
        {
            if (it.quality < 50)
            {
                ++it.quality;
            }
            --it.sellIn;

            if (it.sellIn < 0)
            {
                if (it.quality < 50)
                {
                    ++it.quality;
                }
            }
        }
        else if (it.name == sulfuras)
        {
            if (it.quality < 50)
            {
                ++it.quality;
            }
        }

        else if (it.name == backstage)
        {
            if (it.quality < 50)
            {
                ++it.quality;

                if (it.sellIn < 11)
                {
                    ++it.quality;
                }

                if (it.sellIn < 6)
                {
                    ++it.quality;
                }
            }
            --it.sellIn;

            if (it.sellIn < 0)
            {
                it.quality = 0;
            }
        }
        else
        {
            if (it.quality > 0)
            {
                --it.quality;
            }
            --it.sellIn;

            if (it.sellIn < 0)
            {
                if (it.quality > 0)
                {
                    --it.quality;
                }
            }
        }

    }
}
