#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void qualityIncrement(Item& item)
{
    if (item.quality < 50)
    {
        ++item.quality;
    }
}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        qualityIncrement(items[i]);

        if (items[i].name == "Aged Brie")
        {
            if (--items[i].sellIn < 0)
            {
                qualityIncrement(items[i]);
            }
        }

        else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].sellIn < 11 && items[i].quality <= 50)
            {
                ++items[i].quality;
                if (items[i].sellIn < 6)
                {
                    ++items[i].quality;
                }
            }
            if (--items[i].sellIn < 0)
            {
                items[i].quality = 0;
            }
        }

        else if (items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            if(items[i].quality <= 50)      //anti qualityIncrement
            {
                --items[i].quality;
            }
            --items[i].sellIn;

            if (items[i].quality > 0)
            {
                --items[i].quality;
                if (items[i].sellIn < 0)
                {
                    --items[i].quality;
                }
            }
        }
    }
}
