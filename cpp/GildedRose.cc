#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

const char* Backstage = "Backstage passes to a TAFKAL80ETC concert";
const char* Sulfuras = "Sulfuras, Hand of Ragnaros";
char* AgedBrie = "Aged Brie";
void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != AgedBrie && items[i].name != Backstage && items[i].name != Sulfuras )
        {
            if (items[i].quality > 0)
            {
                --items[i].quality;
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;

                if (items[i].name == Backstage)
                {
                    if (items[i].sellIn < 11)
                    {
                        ++items[i].quality; 
                    }

                    if (items[i].sellIn < 6)
                    {
                        ++items[i].quality;
                    }
                }
            }
        }

        if (items[i].name != Sulfuras)
        {
            --items[i].sellIn;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != AgedBrie)
            {
                if (items[i].name != Backstage)
                {
                    if (items[i].quality > 0 && items[i].name != Sulfuras)
                    {
                        --items[i].quality;

                    }
                }
                else
                {
                    items[i].quality=0;
                }
            }
            else if (items[i].quality < 50)
            {
                ++items[i].quality;
            }
        }
    }
}
