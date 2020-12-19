#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    const char* AGEDBRIE = "Aged Brie";
    const char* BACKSTAGEPASS = "Backstage passes to a TAFKAL80ETC concert";
    const char* SULFURAS = "Sulfuras, Hand of Ragnaros";
  
        // --- refactored code --- // 
for (int i = 0; i < items.size(); i++)
{
        if(items[i].name == AGEDBRIE)
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;
            }
            
                --items[i].sellIn;
            
            if (items[i].sellIn < 0)
            {
                if (items[i].quality < 50)
                {
                    ++items[i].quality;
                }
            }
        }
        else if (items[i].name == BACKSTAGEPASS)
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;
                
                if (items[i].sellIn < 6)
                {
                    ++items[i].quality;
                }
                if (items[i].sellIn < 11)
                {
                    ++items[i].quality; 
                }
            }
            
            --items[i].sellIn;            
            
            if (items[i].sellIn < 0)
            {
                items[i].quality=0;
            }
        }
        
        else if (items[i].name == SULFURAS)
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;
            }
        }
        
        else // Every other item
        {
            if (items[i].quality > 0)
            {
                --items[i].quality;
            }
            
                --items[i].sellIn;
            
            if (items[i].sellIn < 0)
            {
                if (items[i].quality > 0)
                {
                    --items[i].quality;
                }
            }
            
        }
    }
}



