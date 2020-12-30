#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    for (auto elem : items)
    {
        if (elem.name != "Aged Brie" && elem.name != "Backstage passes to a TAFKAL80ETC concert")
        {
            if (elem.quality > 0)
            {
                if (elem.name != "Sulfuras, Hand of Ragnaros")
                {
                    --elem.quality;
                }
            }
        }
        else
        {
            if (elem.quality < 50)
            {
                ++elem.quality;

                if (elem.name == "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (elem.sellIn < 11)
                    {
                        if (elem.quality < 50)
                        {
                            ++elem.quality;
                        }
                    }

                    if (elem.sellIn < 6)
                    {
                        if (elem.quality < 50)
                        {
                            ++elem.quality;
                        }
                    }
                }
            }
        }

        if (elem.name != "Sulfuras, Hand of Ragnaros")
        {
            --elem.sellIn;
        }

        if (elem.sellIn < 0)
        {
            if (elem.name != "Aged Brie")
            {
                if (elem.name != "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (elem.quality > 0)
                    {
                        if (elem.name != "Sulfuras, Hand of Ragnaros")
                        {
                            --elem.quality;
                        }
                    }
                }
                else
                {
                    elem.quality = 0;
                }
            }
            else
            {
                if (elem.quality < 50)
                {
                    ++elem.quality;
                }
            }
        }
    }
}
