#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

class CSOEconItem;

enum EEconItemAttributes : uint32_t
{
    ATTRIBUTE_PAINT_KIT = 6 ,
    ATTRIBUTE_PAINT_SEED = 7 ,
    ATTRIBUTE_PAINT_WEAR = 8 ,
    ATTRIBUTE_STAT_TRACK = 80 ,
    ATTRIBUTE_STAT_TRACK_TYPE = 81 ,
    ATTRIBUTE_STICKER_ID = 113 ,
    ATTRIBUTE_STICKER_WEAR = 114 ,
    ATTRIBUTE_STICKER_SCALE = 115 ,
    ATTRIBUTE_STICKER_ROTATION = 116 ,
    ATTRIBUTE_STICKER_ROTATION_X = 278 ,
    ATTRIBUTE_STICKER_ROTATION_Y = 279 ,
    ATTRIBUTE_MUSIC_ID = 166 ,
    ATTRIBUTE_KEYCHAIN_SLOT_ID_0 = 299,
};

class CEconItem
{
    constexpr static auto Idx_Destruct = 1;

private:
    auto SetDynamicAttributeValue( int index , void* value ) -> void;

public:
    static auto Create() -> CEconItem*;

public:
    auto Destruct() -> void;

public:
    void SetPaintKit( float kit ) { SetDynamicAttributeValue( ATTRIBUTE_PAINT_KIT , &kit ); }
    void SetPaintSeed( float seed ) { SetDynamicAttributeValue( ATTRIBUTE_PAINT_SEED , &seed ); }
    void SetPaintWear( float wear ) { SetDynamicAttributeValue( ATTRIBUTE_PAINT_WEAR , &wear ); }
    void SetStatTrak( int count ) { SetDynamicAttributeValue( ATTRIBUTE_STAT_TRACK , &count ); }
    void SetStatTrakType( int type ) { SetDynamicAttributeValue( ATTRIBUTE_STAT_TRACK_TYPE , &type ); }

    auto SetSticker( int slot , int id ) -> void
    {
        if ( slot < 0 || slot > 5 )
            return;

        SetDynamicAttributeValue( ATTRIBUTE_STICKER_ID + ( slot * 4 ) , &id );
    }

    auto SetSticker( int slot , int id , float wear , float scale , float rotation , float x , float y ) -> void
    {
        if ( slot < 0 || slot > 5 )
            return;

        SetDynamicAttributeValue( ATTRIBUTE_STICKER_ID + ( slot * 4 ) , &id );
        SetDynamicAttributeValue( ATTRIBUTE_STICKER_WEAR + ( slot * 4 ) , &wear );
        SetDynamicAttributeValue( ATTRIBUTE_STICKER_SCALE + ( slot * 4 ) , &scale );
        SetDynamicAttributeValue( ATTRIBUTE_STICKER_ROTATION + ( slot * 4 ) , &rotation );

        SetDynamicAttributeValue( ATTRIBUTE_STICKER_ROTATION_X + ( slot * 2 ) , &x );
        SetDynamicAttributeValue( ATTRIBUTE_STICKER_ROTATION_Y + ( slot * 2 ) , &y );
    }

    auto SetMusicId( int id ) -> void
    {
        SetDynamicAttributeValue( ATTRIBUTE_MUSIC_ID , &id ); // "music id"
    }

    auto SetKeyChainId( int id ) -> void
    {
        SetDynamicAttributeValue( ATTRIBUTE_KEYCHAIN_SLOT_ID_0 , &id ); // "keychain slot 0 id"
    }

    auto SerializeToProtoBufItem( CSOEconItem* pCSOEconItem ) -> void*;

private:
    PAD( 0x10 );

public:
    uint64_t m_ulID;
    uint64_t m_ulOriginalID;
    void* m_pCustomDataOptimizedObject;
    uint32_t m_unAccountID;
    uint32_t m_unInventory;
    uint16_t m_unDefIndex;
    uint16_t m_unOrigin : 5;
    uint16_t m_nQuality : 4;
    uint16_t m_unLevel : 2;
    uint16_t m_nRarity : 4;
    uint16_t m_dirtybitInUse : 1;
    int16_t m_iItemSet;
    int m_bSOUpdateFrame;
    uint8_t m_unFlags;
};
