#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}
bool GildedRose::isUnderHighestQualityValue(int itemQuality) {
    return itemQuality < 50;
}
bool GildedRose::isAboveLowestQualityValue(int itemQuality) {
    return itemQuality > 0;
}
void GildedRose::updateQuality()
{
    std::string x = "Backstage passes to a TAFKAL80ETC concert";
    std::string y = "Sulfuras, Hand of Ragnaros";
    std::string z = "Aged Brie";
    for (int i = 0; i < items.size(); i++)
    {
        std::string itemName = items[i].name;
        
        if(isAboveLowestQualityValue(items[i].quality)) {

        if ((itemName == z || itemName == x || itemName == y ))
        {
             if (isUnderHighestQualityValue(items[i].quality))
            {
                items[i].quality++;
                if (itemName == x)
                {
                    items[i].sellIn < 11 ? items[i].quality++ : false ;
                    items[i].sellIn < 6 ? items[i].quality++ : false ;
                }
            }
        }
        else
        {
            items[i].quality--;  
            
        }
    }

        if (itemName != y)
        {
            items[i].sellIn--;
        }




        if (items[i].sellIn < 0)
        {
            if (itemName != z)
            {
                if (itemName != x )
                {
                    if (isAboveLowestQualityValue(items[i].quality) && itemName != y)
                    {
                     
                            items[i].quality--;
                        
                    }
                }
                else
                {
                    items[i].quality = 0;
                }
            }
            else
            {
                if (isUnderHighestQualityValue(items[i].quality))
                {
                    items[i].quality++;
                }
            }
        }
    }
}
