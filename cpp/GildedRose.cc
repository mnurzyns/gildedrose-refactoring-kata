#include "GildedRose.h"
//create variables holding words
GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    std::string nameOne="Aged Brie";
    std::string nameTwo="Backstage passes to a TAFKAL80ETC concert";
    std::string nameThree="Sulfuras, Hand of Ragnaros";
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != nameOne && items[i].name != nameTwo && items[i].name != nameThree)
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

                if (items[i].name == nameTwo)
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

        if (items[i].name != nameThree)
        {
            --items[i].sellIn;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != nameOne)
            {
                if (items[i].name != nameTwo)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != nameThree)
                        {
                            --items[i].quality;
                        }
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
