#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

const char* Backstage = "Backstage passes to a TAFKAL80ETC concert";
const char* Sulfuras = "Sulfuras, Hand of Ragnaros";
const char* AgedBrie = "Aged Brie";

void GildedRose::updateQuality()
{
    for (auto& it : items)
    {
        if(it.name == AgedBrie)
        {
             --it.sellIn;
            if (it.quality < 50)
            {
                ++it.quality;
            }
            if (it.quality < 50 && it.sellIn < 0)
                {
                     ++it.quality;
                }
        }
        else if(it.name == Backstage)
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


                    --it.sellIn;

                    if (it.sellIn < 0)
                    {

                        it.quality=0;
                    }
            }

        }
        else if(it.name == Sulfuras)
        {
            if (it.quality < 50)
            {
                ++it.quality;
            }


        }
        else {
            --it.sellIn;

            if (it.quality > 0)
            {
                --it.quality;
            }


            if(it.sellIn < 0)
            {
                if(it.quality > 0)
                {
                    --it.quality;
                }
            }
        }
    }
}
