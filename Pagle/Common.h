#pragma once

#include <Windows.h>

#include "Vector3.h"

enum WowObjectType
{
    OBJECT = 0,
    ITEM = 1,
    CONTAINER = 2,
    UNIT = 3,
    PLAYER = 4,
    GAMEOBJECT = 5,
    DYNAMICOBJECT = 6,
    CORPSE = 7,
    AREATRIGGER = 8,
    SCENEOBJECT = 9,
    NUM_CLIENT_OBJECT_TYPES = 0xA
};

struct ObjectFields
{
    uint64_t OBJECT_FIELD_GUID;                                   // 0x0000
    uint32_t OBJECT_FIELD_TYPE;                                   // 0x0008
    uint32_t OBJECT_FIELD_ENTRY;                                  // 0x000C
    uint32_t OBJECT_FIELD_SCALE_X;                                // 0x0010
    uint32_t OBJECT_FIELD_PADDING;                                // 0x0014
};

struct ItemFields
{
    uint64_t ITEM_FIELD_OWNER;                                    // 0x0000
    uint64_t ITEM_FIELD_CONTAINED;                                // 0x0008
    uint64_t ITEM_FIELD_CREATOR;                                  // 0x0010
    uint64_t ITEM_FIELD_GIFTCREATOR;                              // 0x0018
    uint32_t ITEM_FIELD_STACK_COUNT;                              // 0x0020
    uint32_t ITEM_FIELD_DURATION;                                 // 0x0024
    uint32_t ITEM_FIELD_SPELL_CHARGES[5];                         // 0x0028
    uint32_t ITEM_FIELD_FLAGS;                                    // 0x003C
    uint32_t ITEM_FIELD_ENCHANTMENT[33];                          // 0x0040
    uint32_t ITEM_FIELD_PROPERTY_SEED;                            // 0x00C4
    uint32_t ITEM_FIELD_RANDOM_PROPERTIES_ID;                     // 0x00C8
    uint32_t ITEM_FIELD_ITEM_TEXT_ID;                             // 0x00CC
    uint32_t ITEM_FIELD_DURABILITY;                               // 0x00D0
    uint32_t ITEM_FIELD_MAXDURABILITY;                            // 0x00D4
};

struct ContainerFields
{
    uint32_t CONTAINER_FIELD_NUM_SLOTS;                           // 0x0000
    uint32_t CONTAINER_ALIGN_PAD;                                 // 0x0004
    uint32_t CONTAINER_FIELD_SLOT_1[72];                          // 0x0008
};

struct UnitFields
{
    uint64_t UNIT_FIELD_CHARM;                                    // 0x0000
    uint64_t UNIT_FIELD_SUMMON;                                   // 0x0008
    uint64_t UNIT_FIELD_CHARMEDBY;                                // 0x0010
    uint64_t UNIT_FIELD_SUMMONEDBY;                               // 0x0018
    uint64_t UNIT_FIELD_CREATEDBY;                                // 0x0020
    uint64_t UNIT_FIELD_TARGET;                                   // 0x0028
    uint64_t UNIT_FIELD_PERSUADED;                                // 0x0030
    uint64_t UNIT_FIELD_CHANNEL_OBJECT;                           // 0x0038
    uint32_t UNIT_FIELD_HEALTH;                                   // 0x0040
    uint32_t UNIT_FIELD_POWER1;                                   // 0x0044
    uint32_t UNIT_FIELD_POWER2;                                   // 0x0048
    uint32_t UNIT_FIELD_POWER3;                                   // 0x004C
    uint32_t UNIT_FIELD_POWER4;                                   // 0x0050
    uint32_t UNIT_FIELD_POWER5;                                   // 0x0054
    uint32_t UNIT_FIELD_MAXHEALTH;                                // 0x0058
    uint32_t UNIT_FIELD_MAXPOWER1;                                // 0x005C
    uint32_t UNIT_FIELD_MAXPOWER2;                                // 0x0060
    uint32_t UNIT_FIELD_MAXPOWER3;                                // 0x0064
    uint32_t UNIT_FIELD_MAXPOWER4;                                // 0x0068
    uint32_t UNIT_FIELD_MAXPOWER5;                                // 0x006C
    uint32_t UNIT_FIELD_LEVEL;                                    // 0x0070
    uint32_t UNIT_FIELD_FACTIONTEMPLATE;                          // 0x0074
    uint32_t UNIT_FIELD_BYTES_0;                                  // 0x0078
    uint32_t UNIT_VIRTUAL_ITEM_SLOT_DISPLAY[3];                   // 0x007C
    uint32_t UNIT_VIRTUAL_ITEM_INFO[6];                           // 0x0088
    uint32_t UNIT_FIELD_FLAGS;                                    // 0x00A0
    uint32_t UNIT_FIELD_FLAGS_2;                                  // 0x00A4
    uint32_t UNIT_FIELD_AURA[56];                                 // 0x00A8
    uint32_t UNIT_FIELD_AURAFLAGS[14];                            // 0x0188
    uint32_t UNIT_FIELD_AURALEVELS[14];                           // 0x01C0
    uint32_t UNIT_FIELD_AURAAPPLICATIONS[14];                     // 0x01F8
    uint32_t UNIT_FIELD_AURASTATE;                                // 0x0230
    uint64_t UNIT_FIELD_BASEATTACKTIME;                           // 0x0234
    uint32_t UNIT_FIELD_RANGEDATTACKTIME;                         // 0x023C
    uint32_t UNIT_FIELD_BOUNDINGRADIUS;                           // 0x0240
    uint32_t UNIT_FIELD_COMBATREACH;                              // 0x0244
    uint32_t UNIT_FIELD_DISPLAYID;                                // 0x0248
    uint32_t UNIT_FIELD_NATIVEDISPLAYID;                          // 0x024C
    uint32_t UNIT_FIELD_MOUNTDISPLAYID;                           // 0x0250
    uint32_t UNIT_FIELD_MINDAMAGE;                                // 0x0254
    uint32_t UNIT_FIELD_MAXDAMAGE;                                // 0x0258
    uint32_t UNIT_FIELD_MINOFFHANDDAMAGE;                         // 0x025C
    uint32_t UNIT_FIELD_MAXOFFHANDDAMAGE;                         // 0x0260
    uint32_t UNIT_FIELD_BYTES_1;                                  // 0x0264
    uint32_t UNIT_FIELD_PETNUMBER;                                // 0x0268
    uint32_t UNIT_FIELD_PET_NAME_TIMESTAMP;                       // 0x026C
    uint32_t UNIT_FIELD_PETEXPERIENCE;                            // 0x0270
    uint32_t UNIT_FIELD_PETNEXTLEVELEXP;                          // 0x0274
    uint32_t UNIT_DYNAMIC_FLAGS;                                  // 0x0278
    uint32_t UNIT_CHANNEL_SPELL;                                  // 0x027C
    uint32_t UNIT_MOD_CAST_SPEED;                                 // 0x0280
    uint32_t UNIT_CREATED_BY_SPELL;                               // 0x0284
    uint32_t UNIT_NPC_FLAGS;                                      // 0x0288
    uint32_t UNIT_NPC_EMOTESTATE;                                 // 0x028C
    uint32_t UNIT_TRAINING_POINTS;                                // 0x0290
    uint32_t UNIT_FIELD_STAT0;                                    // 0x0294
    uint32_t UNIT_FIELD_STAT1;                                    // 0x0298
    uint32_t UNIT_FIELD_STAT2;                                    // 0x029C
    uint32_t UNIT_FIELD_STAT3;                                    // 0x02A0
    uint32_t UNIT_FIELD_STAT4;                                    // 0x02A4
    uint32_t UNIT_FIELD_POSSTAT0;                                 // 0x02A8
    uint32_t UNIT_FIELD_POSSTAT1;                                 // 0x02AC
    uint32_t UNIT_FIELD_POSSTAT2;                                 // 0x02B0
    uint32_t UNIT_FIELD_POSSTAT3;                                 // 0x02B4
    uint32_t UNIT_FIELD_POSSTAT4;                                 // 0x02B8
    uint32_t UNIT_FIELD_NEGSTAT0;                                 // 0x02BC
    uint32_t UNIT_FIELD_NEGSTAT1;                                 // 0x02C0
    uint32_t UNIT_FIELD_NEGSTAT2;                                 // 0x02C4
    uint32_t UNIT_FIELD_NEGSTAT3;                                 // 0x02C8
    uint32_t UNIT_FIELD_NEGSTAT4;                                 // 0x02CC
    uint32_t UNIT_FIELD_RESISTANCES[7];                           // 0x02D0
    uint32_t UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE[7];            // 0x02EC
    uint32_t UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE[7];            // 0x0308
    uint32_t UNIT_FIELD_BASE_MANA;                                // 0x0324
    uint32_t UNIT_FIELD_BASE_HEALTH;                              // 0x0328
    uint32_t UNIT_FIELD_BYTES_2;                                  // 0x032C
    uint32_t UNIT_FIELD_ATTACK_POWER;                             // 0x0330
    uint32_t UNIT_FIELD_ATTACK_POWER_MODS;                        // 0x0334
    uint32_t UNIT_FIELD_ATTACK_POWER_MULTIPLIER;                  // 0x0338
    uint32_t UNIT_FIELD_RANGED_ATTACK_POWER;                      // 0x033C
    uint32_t UNIT_FIELD_RANGED_ATTACK_POWER_MODS;                 // 0x0340
    uint32_t UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER;           // 0x0344
    uint32_t UNIT_FIELD_MINRANGEDDAMAGE;                          // 0x0348
    uint32_t UNIT_FIELD_MAXRANGEDDAMAGE;                          // 0x034C
    uint32_t UNIT_FIELD_POWER_COST_MODIFIER[7];                   // 0x0350
    uint32_t UNIT_FIELD_POWER_COST_MULTIPLIER[7];                 // 0x036C
    uint32_t UNIT_FIELD_MAXHEALTHMODIFIER;                        // 0x0388
    uint32_t UNIT_FIELD_PADDING;                                  // 0x038C
};

struct PlayerFields
{
    uint64_t PLAYER_DUEL_ARBITER;                                 // 0x0000
    uint32_t PLAYER_FLAGS;                                        // 0x0008
    uint32_t PLAYER_GUILDID;                                      // 0x000C
    uint32_t PLAYER_GUILDRANK;                                    // 0x0010
    uint32_t PLAYER_BYTES;                                        // 0x0014
    uint32_t PLAYER_BYTES_2;                                      // 0x0018
    uint32_t PLAYER_BYTES_3;                                      // 0x001C
    uint32_t PLAYER_DUEL_TEAM;                                    // 0x0020
    uint32_t PLAYER_GUILD_TIMESTAMP;                              // 0x0024
    uint32_t PLAYER_QUEST_LOG_1_1;                                // 0x0028
    uint32_t PLAYER_QUEST_LOG_1_2;                                // 0x002C
    uint32_t PLAYER_QUEST_LOG_1_3;                                // 0x0030
    uint32_t PLAYER_QUEST_LOG_1_4;                                // 0x0034
    uint32_t PLAYER_QUEST_LOG_2_1;                                // 0x0038
    uint32_t PLAYER_QUEST_LOG_2_2;                                // 0x003C
    uint32_t PLAYER_QUEST_LOG_2_3;                                // 0x0040
    uint32_t PLAYER_QUEST_LOG_2_4;                                // 0x0044
    uint32_t PLAYER_QUEST_LOG_3_1;                                // 0x0048
    uint32_t PLAYER_QUEST_LOG_3_2;                                // 0x004C
    uint32_t PLAYER_QUEST_LOG_3_3;                                // 0x0050
    uint32_t PLAYER_QUEST_LOG_3_4;                                // 0x0054
    uint32_t PLAYER_QUEST_LOG_4_1;                                // 0x0058
    uint32_t PLAYER_QUEST_LOG_4_2;                                // 0x005C
    uint32_t PLAYER_QUEST_LOG_4_3;                                // 0x0060
    uint32_t PLAYER_QUEST_LOG_4_4;                                // 0x0064
    uint32_t PLAYER_QUEST_LOG_5_1;                                // 0x0068
    uint32_t PLAYER_QUEST_LOG_5_2;                                // 0x006C
    uint32_t PLAYER_QUEST_LOG_5_3;                                // 0x0070
    uint32_t PLAYER_QUEST_LOG_5_4;                                // 0x0074
    uint32_t PLAYER_QUEST_LOG_6_1;                                // 0x0078
    uint32_t PLAYER_QUEST_LOG_6_2;                                // 0x007C
    uint32_t PLAYER_QUEST_LOG_6_3;                                // 0x0080
    uint32_t PLAYER_QUEST_LOG_6_4;                                // 0x0084
    uint32_t PLAYER_QUEST_LOG_7_1;                                // 0x0088
    uint32_t PLAYER_QUEST_LOG_7_2;                                // 0x008C
    uint32_t PLAYER_QUEST_LOG_7_3;                                // 0x0090
    uint32_t PLAYER_QUEST_LOG_7_4;                                // 0x0094
    uint32_t PLAYER_QUEST_LOG_8_1;                                // 0x0098
    uint32_t PLAYER_QUEST_LOG_8_2;                                // 0x009C
    uint32_t PLAYER_QUEST_LOG_8_3;                                // 0x00A0
    uint32_t PLAYER_QUEST_LOG_8_4;                                // 0x00A4
    uint32_t PLAYER_QUEST_LOG_9_1;                                // 0x00A8
    uint32_t PLAYER_QUEST_LOG_9_2;                                // 0x00AC
    uint32_t PLAYER_QUEST_LOG_9_3;                                // 0x00B0
    uint32_t PLAYER_QUEST_LOG_9_4;                                // 0x00B4
    uint32_t PLAYER_QUEST_LOG_10_1;                               // 0x00B8
    uint32_t PLAYER_QUEST_LOG_10_2;                               // 0x00BC
    uint32_t PLAYER_QUEST_LOG_10_3;                               // 0x00C0
    uint32_t PLAYER_QUEST_LOG_10_4;                               // 0x00C4
    uint32_t PLAYER_QUEST_LOG_11_1;                               // 0x00C8
    uint32_t PLAYER_QUEST_LOG_11_2;                               // 0x00CC
    uint32_t PLAYER_QUEST_LOG_11_3;                               // 0x00D0
    uint32_t PLAYER_QUEST_LOG_11_4;                               // 0x00D4
    uint32_t PLAYER_QUEST_LOG_12_1;                               // 0x00D8
    uint32_t PLAYER_QUEST_LOG_12_2;                               // 0x00DC
    uint32_t PLAYER_QUEST_LOG_12_3;                               // 0x00E0
    uint32_t PLAYER_QUEST_LOG_12_4;                               // 0x00E4
    uint32_t PLAYER_QUEST_LOG_13_1;                               // 0x00E8
    uint32_t PLAYER_QUEST_LOG_13_2;                               // 0x00EC
    uint32_t PLAYER_QUEST_LOG_13_3;                               // 0x00F0
    uint32_t PLAYER_QUEST_LOG_13_4;                               // 0x00F4
    uint32_t PLAYER_QUEST_LOG_14_1;                               // 0x00F8
    uint32_t PLAYER_QUEST_LOG_14_2;                               // 0x00FC
    uint32_t PLAYER_QUEST_LOG_14_3;                               // 0x0100
    uint32_t PLAYER_QUEST_LOG_14_4;                               // 0x0104
    uint32_t PLAYER_QUEST_LOG_15_1;                               // 0x0108
    uint32_t PLAYER_QUEST_LOG_15_2;                               // 0x010C
    uint32_t PLAYER_QUEST_LOG_15_3;                               // 0x0110
    uint32_t PLAYER_QUEST_LOG_15_4;                               // 0x0114
    uint32_t PLAYER_QUEST_LOG_16_1;                               // 0x0118
    uint32_t PLAYER_QUEST_LOG_16_2;                               // 0x011C
    uint32_t PLAYER_QUEST_LOG_16_3;                               // 0x0120
    uint32_t PLAYER_QUEST_LOG_16_4;                               // 0x0124
    uint32_t PLAYER_QUEST_LOG_17_1;                               // 0x0128
    uint32_t PLAYER_QUEST_LOG_17_2;                               // 0x012C
    uint32_t PLAYER_QUEST_LOG_17_3;                               // 0x0130
    uint32_t PLAYER_QUEST_LOG_17_4;                               // 0x0134
    uint32_t PLAYER_QUEST_LOG_18_1;                               // 0x0138
    uint32_t PLAYER_QUEST_LOG_18_2;                               // 0x013C
    uint32_t PLAYER_QUEST_LOG_18_3;                               // 0x0140
    uint32_t PLAYER_QUEST_LOG_18_4;                               // 0x0144
    uint32_t PLAYER_QUEST_LOG_19_1;                               // 0x0148
    uint32_t PLAYER_QUEST_LOG_19_2;                               // 0x014C
    uint32_t PLAYER_QUEST_LOG_19_3;                               // 0x0150
    uint32_t PLAYER_QUEST_LOG_19_4;                               // 0x0154
    uint32_t PLAYER_QUEST_LOG_20_1;                               // 0x0158
    uint32_t PLAYER_QUEST_LOG_20_2;                               // 0x015C
    uint32_t PLAYER_QUEST_LOG_20_3;                               // 0x0160
    uint32_t PLAYER_QUEST_LOG_20_4;                               // 0x0164
    uint32_t PLAYER_QUEST_LOG_21_1;                               // 0x0168
    uint32_t PLAYER_QUEST_LOG_21_2;                               // 0x016C
    uint32_t PLAYER_QUEST_LOG_21_3;                               // 0x0170
    uint32_t PLAYER_QUEST_LOG_21_4;                               // 0x0174
    uint32_t PLAYER_QUEST_LOG_22_1;                               // 0x0178
    uint32_t PLAYER_QUEST_LOG_22_2;                               // 0x017C
    uint32_t PLAYER_QUEST_LOG_22_3;                               // 0x0180
    uint32_t PLAYER_QUEST_LOG_22_4;                               // 0x0184
    uint32_t PLAYER_QUEST_LOG_23_1;                               // 0x0188
    uint32_t PLAYER_QUEST_LOG_23_2;                               // 0x018C
    uint32_t PLAYER_QUEST_LOG_23_3;                               // 0x0190
    uint32_t PLAYER_QUEST_LOG_23_4;                               // 0x0194
    uint32_t PLAYER_QUEST_LOG_24_1;                               // 0x0198
    uint32_t PLAYER_QUEST_LOG_24_2;                               // 0x019C
    uint32_t PLAYER_QUEST_LOG_24_3;                               // 0x01A0
    uint32_t PLAYER_QUEST_LOG_24_4;                               // 0x01A4
    uint32_t PLAYER_QUEST_LOG_25_1;                               // 0x01A8
    uint32_t PLAYER_QUEST_LOG_25_2;                               // 0x01AC
    uint32_t PLAYER_QUEST_LOG_25_3;                               // 0x01B0
    uint32_t PLAYER_QUEST_LOG_25_4;                               // 0x01B4
    uint64_t PLAYER_VISIBLE_ITEM_1_CREATOR;                       // 0x01B8
    uint32_t PLAYER_VISIBLE_ITEM_1_0[12];                         // 0x01C0
    uint32_t PLAYER_VISIBLE_ITEM_1_PROPERTIES;                    // 0x01F0
    uint32_t PLAYER_VISIBLE_ITEM_1_PAD;                           // 0x01F4
    uint64_t PLAYER_VISIBLE_ITEM_2_CREATOR;                       // 0x01F8
    uint32_t PLAYER_VISIBLE_ITEM_2_0[12];                         // 0x0200
    uint32_t PLAYER_VISIBLE_ITEM_2_PROPERTIES;                    // 0x0230
    uint32_t PLAYER_VISIBLE_ITEM_2_PAD;                           // 0x0234
    uint64_t PLAYER_VISIBLE_ITEM_3_CREATOR;                       // 0x0238
    uint32_t PLAYER_VISIBLE_ITEM_3_0[12];                         // 0x0240
    uint32_t PLAYER_VISIBLE_ITEM_3_PROPERTIES;                    // 0x0270
    uint32_t PLAYER_VISIBLE_ITEM_3_PAD;                           // 0x0274
    uint64_t PLAYER_VISIBLE_ITEM_4_CREATOR;                       // 0x0278
    uint32_t PLAYER_VISIBLE_ITEM_4_0[12];                         // 0x0280
    uint32_t PLAYER_VISIBLE_ITEM_4_PROPERTIES;                    // 0x02B0
    uint32_t PLAYER_VISIBLE_ITEM_4_PAD;                           // 0x02B4
    uint64_t PLAYER_VISIBLE_ITEM_5_CREATOR;                       // 0x02B8
    uint32_t PLAYER_VISIBLE_ITEM_5_0[12];                         // 0x02C0
    uint32_t PLAYER_VISIBLE_ITEM_5_PROPERTIES;                    // 0x02F0
    uint32_t PLAYER_VISIBLE_ITEM_5_PAD;                           // 0x02F4
    uint64_t PLAYER_VISIBLE_ITEM_6_CREATOR;                       // 0x02F8
    uint32_t PLAYER_VISIBLE_ITEM_6_0[12];                         // 0x0300
    uint32_t PLAYER_VISIBLE_ITEM_6_PROPERTIES;                    // 0x0330
    uint32_t PLAYER_VISIBLE_ITEM_6_PAD;                           // 0x0334
    uint64_t PLAYER_VISIBLE_ITEM_7_CREATOR;                       // 0x0338
    uint32_t PLAYER_VISIBLE_ITEM_7_0[12];                         // 0x0340
    uint32_t PLAYER_VISIBLE_ITEM_7_PROPERTIES;                    // 0x0370
    uint32_t PLAYER_VISIBLE_ITEM_7_PAD;                           // 0x0374
    uint64_t PLAYER_VISIBLE_ITEM_8_CREATOR;                       // 0x0378
    uint32_t PLAYER_VISIBLE_ITEM_8_0[12];                         // 0x0380
    uint32_t PLAYER_VISIBLE_ITEM_8_PROPERTIES;                    // 0x03B0
    uint32_t PLAYER_VISIBLE_ITEM_8_PAD;                           // 0x03B4
    uint64_t PLAYER_VISIBLE_ITEM_9_CREATOR;                       // 0x03B8
    uint32_t PLAYER_VISIBLE_ITEM_9_0[12];                         // 0x03C0
    uint32_t PLAYER_VISIBLE_ITEM_9_PROPERTIES;                    // 0x03F0
    uint32_t PLAYER_VISIBLE_ITEM_9_PAD;                           // 0x03F4
    uint64_t PLAYER_VISIBLE_ITEM_10_CREATOR;                      // 0x03F8
    uint32_t PLAYER_VISIBLE_ITEM_10_0[12];                        // 0x0400
    uint32_t PLAYER_VISIBLE_ITEM_10_PROPERTIES;                   // 0x0430
    uint32_t PLAYER_VISIBLE_ITEM_10_PAD;                          // 0x0434
    uint64_t PLAYER_VISIBLE_ITEM_11_CREATOR;                      // 0x0438
    uint32_t PLAYER_VISIBLE_ITEM_11_0[12];                        // 0x0440
    uint32_t PLAYER_VISIBLE_ITEM_11_PROPERTIES;                   // 0x0470
    uint32_t PLAYER_VISIBLE_ITEM_11_PAD;                          // 0x0474
    uint64_t PLAYER_VISIBLE_ITEM_12_CREATOR;                      // 0x0478
    uint32_t PLAYER_VISIBLE_ITEM_12_0[12];                        // 0x0480
    uint32_t PLAYER_VISIBLE_ITEM_12_PROPERTIES;                   // 0x04B0
    uint32_t PLAYER_VISIBLE_ITEM_12_PAD;                          // 0x04B4
    uint64_t PLAYER_VISIBLE_ITEM_13_CREATOR;                      // 0x04B8
    uint32_t PLAYER_VISIBLE_ITEM_13_0[12];                        // 0x04C0
    uint32_t PLAYER_VISIBLE_ITEM_13_PROPERTIES;                   // 0x04F0
    uint32_t PLAYER_VISIBLE_ITEM_13_PAD;                          // 0x04F4
    uint64_t PLAYER_VISIBLE_ITEM_14_CREATOR;                      // 0x04F8
    uint32_t PLAYER_VISIBLE_ITEM_14_0[12];                        // 0x0500
    uint32_t PLAYER_VISIBLE_ITEM_14_PROPERTIES;                   // 0x0530
    uint32_t PLAYER_VISIBLE_ITEM_14_PAD;                          // 0x0534
    uint64_t PLAYER_VISIBLE_ITEM_15_CREATOR;                      // 0x0538
    uint32_t PLAYER_VISIBLE_ITEM_15_0[12];                        // 0x0540
    uint32_t PLAYER_VISIBLE_ITEM_15_PROPERTIES;                   // 0x0570
    uint32_t PLAYER_VISIBLE_ITEM_15_PAD;                          // 0x0574
    uint64_t PLAYER_VISIBLE_ITEM_16_CREATOR;                      // 0x0578
    uint32_t PLAYER_VISIBLE_ITEM_16_0[12];                        // 0x0580
    uint32_t PLAYER_VISIBLE_ITEM_16_PROPERTIES;                   // 0x05B0
    uint32_t PLAYER_VISIBLE_ITEM_16_PAD;                          // 0x05B4
    uint64_t PLAYER_VISIBLE_ITEM_17_CREATOR;                      // 0x05B8
    uint32_t PLAYER_VISIBLE_ITEM_17_0[12];                        // 0x05C0
    uint32_t PLAYER_VISIBLE_ITEM_17_PROPERTIES;                   // 0x05F0
    uint32_t PLAYER_VISIBLE_ITEM_17_PAD;                          // 0x05F4
    uint64_t PLAYER_VISIBLE_ITEM_18_CREATOR;                      // 0x05F8
    uint32_t PLAYER_VISIBLE_ITEM_18_0[12];                        // 0x0600
    uint32_t PLAYER_VISIBLE_ITEM_18_PROPERTIES;                   // 0x0630
    uint32_t PLAYER_VISIBLE_ITEM_18_PAD;                          // 0x0634
    uint64_t PLAYER_VISIBLE_ITEM_19_CREATOR;                      // 0x0638
    uint32_t PLAYER_VISIBLE_ITEM_19_0[12];                        // 0x0640
    uint32_t PLAYER_VISIBLE_ITEM_19_PROPERTIES;                   // 0x0670
    uint32_t PLAYER_VISIBLE_ITEM_19_PAD;                          // 0x0674
    uint32_t PLAYER_CHOSEN_TITLE;                                 // 0x0678
    uint32_t PLAYER_FIELD_PAD_0;                                  // 0x067C
    uint32_t PLAYER_FIELD_INV_SLOT_HEAD[46];                      // 0x0680
    uint32_t PLAYER_FIELD_PACK_SLOT_1[32];                        // 0x0738
    uint32_t PLAYER_FIELD_BANK_SLOT_1[56];                        // 0x07B8
    uint32_t PLAYER_FIELD_BANKBAG_SLOT_1[14];                     // 0x0898
    uint32_t PLAYER_FIELD_VENDORBUYBACK_SLOT_1[24];               // 0x08D0
    uint32_t PLAYER_FIELD_KEYRING_SLOT_1[64];                     // 0x0930
    uint32_t PLAYER_FIELD_VANITYPET_SLOT_1[36];                   // 0x0A30
    uint64_t PLAYER_FARSIGHT;                                     // 0x0AC0
    uint64_t PLAYER__FIELD_KNOWN_TITLES;                          // 0x0AC8
    uint32_t PLAYER_XP;                                           // 0x0AD0
    uint32_t PLAYER_NEXT_LEVEL_XP;                                // 0x0AD4
    uint32_t PLAYER_SKILL_INFO_1_1[384];                          // 0x0AD8
    uint32_t PLAYER_CHARACTER_POINTS1;                            // 0x10D8
    uint32_t PLAYER_CHARACTER_POINTS2;                            // 0x10DC
    uint32_t PLAYER_TRACK_CREATURES;                              // 0x10E0
    uint32_t PLAYER_TRACK_RESOURCES;                              // 0x10E4
    uint32_t PLAYER_BLOCK_PERCENTAGE;                             // 0x10E8
    uint32_t PLAYER_DODGE_PERCENTAGE;                             // 0x10EC
    uint32_t PLAYER_PARRY_PERCENTAGE;                             // 0x10F0
    uint32_t PLAYER_EXPERTISE;                                    // 0x10F4
    uint32_t PLAYER_OFFHAND_EXPERTISE;                            // 0x10F8
    uint32_t PLAYER_CRIT_PERCENTAGE;                              // 0x10FC
    uint32_t PLAYER_RANGED_CRIT_PERCENTAGE;                       // 0x1100
    uint32_t PLAYER_OFFHAND_CRIT_PERCENTAGE;                      // 0x1104
    uint32_t PLAYER_SPELL_CRIT_PERCENTAGE1[7];                    // 0x1108
    uint32_t PLAYER_SHIELD_BLOCK;                                 // 0x1124
    uint32_t PLAYER_EXPLORED_ZONES_1[128];                        // 0x1128
    uint32_t PLAYER_REST_STATE_EXPERIENCE;                        // 0x1328
    uint32_t PLAYER_FIELD_COINAGE;                                // 0x132C
    uint32_t PLAYER_FIELD_MOD_DAMAGE_DONE_POS[7];                 // 0x1330
    uint32_t PLAYER_FIELD_MOD_DAMAGE_DONE_NEG[7];                 // 0x134C
    uint32_t PLAYER_FIELD_MOD_DAMAGE_DONE_PCT[7];                 // 0x1368
    uint32_t PLAYER_FIELD_MOD_HEALING_DONE_POS;                   // 0x1384
    uint32_t PLAYER_FIELD_MOD_TARGET_RESISTANCE;                  // 0x1388
    uint32_t PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE;         // 0x138C
    uint32_t PLAYER_FIELD_BYTES;                                  // 0x1390
    uint32_t PLAYER_AMMO_ID;                                      // 0x1394
    uint32_t PLAYER_SELF_RES_SPELL;                               // 0x1398
    uint32_t PLAYER_FIELD_PVP_MEDALS;                             // 0x139C
    uint32_t PLAYER_FIELD_BUYBACK_PRICE_1[12];                    // 0x13A0
    uint32_t PLAYER_FIELD_BUYBACK_TIMESTAMP_1[12];                // 0x13D0
    uint32_t PLAYER_FIELD_KILLS;                                  // 0x1400
    uint32_t PLAYER_FIELD_TODAY_CONTRIBUTION;                     // 0x1404
    uint32_t PLAYER_FIELD_YESTERDAY_CONTRIBUTION;                 // 0x1408
    uint32_t PLAYER_FIELD_LIFETIME_HONORBALE_KILLS;               // 0x140C
    uint32_t PLAYER_FIELD_BYTES2;                                 // 0x1410
    uint32_t PLAYER_FIELD_WATCHED_FACTION_INDEX;                  // 0x1414
    uint32_t PLAYER_FIELD_COMBAT_RATING_1[24];                    // 0x1418
    uint32_t PLAYER_FIELD_ARENA_TEAM_INFO_1_1[18];                // 0x1478
    uint32_t PLAYER_FIELD_HONOR_CURRENCY;                         // 0x14C0
    uint32_t PLAYER_FIELD_ARENA_CURRENCY;                         // 0x14C4
    uint32_t PLAYER_FIELD_MOD_MANA_REGEN;                         // 0x14C8
    uint32_t PLAYER_FIELD_MOD_MANA_REGEN_INTERRUPT;               // 0x14CC
    uint32_t PLAYER_FIELD_MAX_LEVEL;                              // 0x14D0
    uint32_t PLAYER_FIELD_DAILY_QUESTS_1[25];                     // 0x14D4
};

struct GameObjectFields
{
    uint64_t GAMEOBJECT_CREATED_BY;                               // 0x0000
    uint32_t GAMEOBJECT_DISPLAYID;                                // 0x0008
    uint32_t GAMEOBJECT_FLAGS;                                    // 0x000C
    uint32_t GAMEOBJECT_ROTATION[4];                              // 0x0010
    uint32_t GAMEOBJECT_STATE;                                    // 0x0020
    float GAMEOBJECT_POS_X;                                       // 0x0024
    float GAMEOBJECT_POS_Y;                                       // 0x0028
    float GAMEOBJECT_POS_Z;                                       // 0x002C
    float GAMEOBJECT_FACING;                                      // 0x0030
    uint32_t GAMEOBJECT_DYN_FLAGS;                                // 0x0034
    uint32_t GAMEOBJECT_FACTION;                                  // 0x0038
    uint32_t GAMEOBJECT_TYPE_ID;                                  // 0x003C
    uint32_t GAMEOBJECT_LEVEL;                                    // 0x0040
    uint32_t GAMEOBJECT_ARTKIT;                                   // 0x0044
    uint32_t GAMEOBJECT_ANIMPROGRESS;                             // 0x0048
    uint32_t GAMEOBJECT_PADDING;                                  // 0x004C
};

struct DynamicObjectFields
{
    uint64_t DYNAMICOBJECT_CASTER;                                // 0x0000
    uint32_t DYNAMICOBJECT_BYTES;                                 // 0x0008
    uint32_t DYNAMICOBJECT_SPELLID;                               // 0x000C
    uint32_t DYNAMICOBJECT_RADIUS;                                // 0x0010
    uint32_t DYNAMICOBJECT_POS_X;                                 // 0x0014
    uint32_t DYNAMICOBJECT_POS_Y;                                 // 0x0018
    uint32_t DYNAMICOBJECT_POS_Z;                                 // 0x001C
    uint32_t DYNAMICOBJECT_FACING;                                // 0x0020
    uint32_t DYNAMICOBJECT_CASTTIME;                              // 0x0024
};

struct CorpseFields
{
    uint64_t CORPSE_FIELD_OWNER;
    uint64_t CORPSE_FIELD_PARTY;
    uint32_t CORPSE_FIELD_FACING;
    uint32_t CORPSE_FIELD_POS_X;
    uint32_t CORPSE_FIELD_POS_Y;
    uint32_t CORPSE_FIELD_POS_Z;
    uint32_t CORPSE_FIELD_DISPLAY_ID;
    uint32_t CORPSE_FIELD_ITEM[19];
    uint32_t CORPSE_FIELD_BYTES_1;
    uint32_t CORPSE_FIELD_BYTES_2;
    uint32_t CORPSE_FIELD_GUILD;
    uint32_t CORPSE_FIELD_FLAGS;
    uint32_t CORPSE_FIELD_DYNAMIC_FLAGS;
    uint32_t CORPSE_FIELD_PAD;
};

class WowObject
{
public:
    char unknown0[8];
    uint32_t DataPtr;
    char unknown12[8];
    uint32_t ObjectType;
    char unknown24[24];
    uint64_t GUID;
    char unknown50[4];
    intptr_t NextObject;
};
