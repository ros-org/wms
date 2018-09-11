/******************************************************************************
** uaeuinformation.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.
**
** Software License Agreement ("SLA") Version 2.5
**
** Unless explicitly acquired and licensed from Licensor under another
** license, the contents of this file are subject to the Software License
** Agreement ("SLA") Version 2.5, or subsequent versions
** as allowed by the SLA, and You may not copy or use this file in either
** source code or executable form, except in compliance with the terms and
** conditions of the SLA.
**
** All software distributed under the SLA is provided strictly on an
** "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
** AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
** LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific
** language governing rights and limitations under the SLA.
**
** The complete license agreement can be found here:
** http://unifiedautomation.com/License/SLA/2.5/
**
** Project: C++ OPC SDK base module
**
** Portable UaEUInformation class.
**
******************************************************************************/
#ifndef UAEUINFORMATION_H
#define UAEUINFORMATION_H

#include <opcua_proxystub.h>

#include "uabase.h"
#include "ualocalizedtext.h"
#include "uastring.h"
#include "uaarraytemplates.h"

class UaExtensionObject;
class UaVariant;
class UaDataValue;

class UABASE_EXPORT UaEUInformationPrivate;

/** @ingroup CppBaseLibraryClass
 *  @brief Wrapper class for the UA stack structure OpcUa_EUInformation.
 *
 *  This class encapsulates the native OpcUa_EUInformation structure
 *  and handles memory allocation and cleanup for you.
 *  UaEUInformation uses implicit sharing to avoid needless copying and to boost the performance.
 *  Only if you modify a shared EUInformation it creates a copy for that (copy-on-write).
 *  So assigning another UaEUInformation or passing it as parameter needs constant time and is nearly as fast as assigning a pointer.
 *
 *  Contains information about the EngineeringUnits.
 *
 *  Understanding the units of a measurement value is essential for a uniform
 *  system. In an open system in particular where servers from different cultures
 *  might be used, it is essential to know what the units of measurement are. Based
 *  on such knowledge, values can be converted if necessary before being used.
 *  Therefore, although defined as optional, support of the EngineeringUnits
 *  Property is strongly advised.
 *
 *  To facilitate interoperability, OPC UA specifies how to apply the widely
 *  accepted “Codes for Units of Measurement (Recommendation No. 20)” published by
 *  the “United Nations Centre for Trade Facilitation and Electronic Business” (see
 *  UN/CEFACT). It uses and is based on the International System of Units (SI
 *  Units) but in addition provides a fixed code that can be used for automated
 *  evaluation. This recommendation has been accepted by many industries on a
 *  global basis.
 */
class UABASE_EXPORT UaEUInformation
{
    UA_DECLARE_PRIVATE(UaEUInformation)
public:
enum EngineeringUnit
{
    EngineeringUnit_group = 12592, /*  */
    EngineeringUnit_outfit = 12593, /*  */
    EngineeringUnit_ration = 12595, /*  */
    EngineeringUnit_shot = 12596, /*  */
    EngineeringUnit_stick__military = 12597, /*  */
    EngineeringUnit_fixed_rate = 12617, /*  */
    EngineeringUnit_twenty_foot_container = 12848, /*  */
    EngineeringUnit_forty_foot_container = 12849, /*  */
    EngineeringUnit_decilitre_per_gram = 12850, /* dl/g */
    EngineeringUnit_gram_per_cubic_centimetre = 12851, /* g/cm³ */
    EngineeringUnit_theoretical_pound = 12852, /*  */
    EngineeringUnit_gram_per_square_centimetre = 12853, /* g/cm² */
    EngineeringUnit_theoretical_ton = 12855, /*  */
    EngineeringUnit_kilogram_per_square_metre = 12856, /* kg/m² */
    EngineeringUnit_radian_per_second = 12865, /* rad/s */
    EngineeringUnit_radian_per_second_squared = 12866, /* rad/s² */
    EngineeringUnit_roentgen = 12867, /* R */
    EngineeringUnit_volt_AC = 12871, /* V */
    EngineeringUnit_volt_DC = 12872, /* V */
    EngineeringUnit_British_thermal_unit__international_table__per_hour = 12873, /* BtuIT/h */
    EngineeringUnit_cubic_centimetre_per_second = 12874, /* cm³/s */
    EngineeringUnit_cubic_foot_per_hour = 12875, /* ft³/h */
    EngineeringUnit_cubic_foot_per_minute = 12876, /* ft³/min */
    EngineeringUnit_centimetre_per_second = 12877, /* cm/s */
    EngineeringUnit_decibel = 12878, /* dB */
    EngineeringUnit_kilobyte = 12880, /* kbyte */
    EngineeringUnit_kilobecquerel = 12881, /* kBq */
    EngineeringUnit_kilocurie = 12882, /* kCi */
    EngineeringUnit_megagram = 12885, /* Mg */
    EngineeringUnit_metre_per_minute = 12888, /* m/min */
    EngineeringUnit_milliroentgen = 12889, /* mR */
    EngineeringUnit_millivolt = 12890, /* mV */
    EngineeringUnit_kilopascal_square_metre_per_gram = 13107, /* kPa·m²/g */
    EngineeringUnit_kilopascal_per_millimetre = 13108, /* kPa/mm */
    EngineeringUnit_millilitre_per_square_centimetre_second = 13109, /* ml/(cm²·s) */
    EngineeringUnit_ounce_per_square_foot = 13111, /* oz/ft² */
    EngineeringUnit_ounce_per_square_foot_per_0_01inch = 13112, /* oz/(ft²/cin) */
    EngineeringUnit_megajoule = 13122, /* MJ */
    EngineeringUnit_manmonth = 13123, /*  */
    EngineeringUnit_millilitre_per_second = 13360, /* ml/s */
    EngineeringUnit_millilitre_per_minute = 13361, /* ml/min */
    EngineeringUnit_centistokes = 13379, /* cSt */
    EngineeringUnit_microlitre = 13383, /* µl */
    EngineeringUnit_micrometre__micron_ = 13384, /* µm */
    EngineeringUnit_milliampere = 13387, /* mA */
    EngineeringUnit_megabyte = 13388, /* Mbyte */
    EngineeringUnit_milligram_per_hour = 13389, /* mg/h */
    EngineeringUnit_megabecquerel = 13390, /* MBq */
    EngineeringUnit_microfarad = 13391, /* µF */
    EngineeringUnit_newton_per_metre = 13392, /* N/m */
    EngineeringUnit_ounce_inch = 13393, /* oz·in */
    EngineeringUnit_ounce_foot = 13394, /* oz·ft */
    EngineeringUnit_picofarad = 13396, /* pF */
    EngineeringUnit_pound_per_hour = 13397, /* lb/h */
    EngineeringUnit_ton__US__per_hour = 13399, /* ton (US) /h */
    EngineeringUnit_kilolitre_per_hour = 13400, /* kl/h */
    EngineeringUnit_sitas = 13622, /*  */
    EngineeringUnit_mesh = 13623, /*  */
    EngineeringUnit_net_kilogram = 13624, /*  */
    EngineeringUnit_part_per_million = 13625, /* ppm */
    EngineeringUnit_barrel__US__per_minute = 13633, /* barrel (US)/min */
    EngineeringUnit_batch = 13634, /*  */
    EngineeringUnit_MMSCF_day = 13637, /*  */
    EngineeringUnit_hydraulic_horse_power = 13642, /*  */
    EngineeringUnit_percent_weight = 13872, /*  */
    EngineeringUnit_part_per_billion__US_ = 13873, /* ppb */
    EngineeringUnit_pound_per_square_inch__gauge = 13876, /*  */
    EngineeringUnit_oersted = 13878, /* Oe */
    EngineeringUnit_millipascal = 14132, /* mPa */
    EngineeringUnit_gauss = 14134, /* Gs */
    EngineeringUnit_milli_inch = 14135, /* mil */
    EngineeringUnit_kilogauss = 14136, /* kGs */
    EngineeringUnit_pound_per_square_inch_absolute = 14384, /* lb/in² */
    EngineeringUnit_henry = 14385, /* H */
    EngineeringUnit_A_unit_of_pressure_defining_the_number_of_kilopounds_force_per_square_inch__Use_kip_per_square_inch__common_code_N20__ = 14388, /* klbf/in² */
    EngineeringUnit_foot_pound_force = 14389, /* ft·lbf */
    EngineeringUnit_pound_per_cubic_foot = 14391, /* lb/ft³ */
    EngineeringUnit_poise = 14393, /* P */
    EngineeringUnit_stokes = 14641, /* St */
    EngineeringUnit_S15___C_calorie = 16689, /* cal15 */
    EngineeringUnit_ampere_square_metre_per_joule_second = 4272432, /* A·m²/(J·s) */
    EngineeringUnit_angstrom = 4272433, /* Å */
    EngineeringUnit_astronomical_unit = 4272434, /* ua */
    EngineeringUnit_attojoule = 4272435, /* aJ */
    EngineeringUnit_barn = 4272436, /* b */
    EngineeringUnit_barn_per_electronvolt = 4272437, /* b/eV */
    EngineeringUnit_barn_per_steradian_electronvolt = 4272438, /* b/(sr·eV) */
    EngineeringUnit_barn_per_steradian = 4272439, /* b/sr */
    EngineeringUnit_becquerel_per_kilogram = 4272440, /* Bq/kg */
    EngineeringUnit_becquerel_per_cubic_metre = 4272441, /* Bq/m³ */
    EngineeringUnit_ampere_per_centimetre = 16690, /* A/cm */
    EngineeringUnit_British_thermal_unit__international_table__per_second_square_foot_degree_Rankine = 4272688, /* BtuIT/(s·ft²·°R) */
    EngineeringUnit_British_thermal_unit__international_table__per_pound_degree_Rankine = 4272689, /* Btu/IT(lb·°R) */
    EngineeringUnit_British_thermal_unit__international_table__per_second_foot_degree_Rankine = 4272690, /* BtuIT/(s·ft·°R) */
    EngineeringUnit_British_thermal_unit__international_table__per_hour_square_foot_degree_Rankine = 4272691, /* BtuIT/(h·ft²·°R) */
    EngineeringUnit_candela_per_square_metre = 4272692, /* cd/m² */
    EngineeringUnit_cheval_vapeur = 4272693, /* CV */
    EngineeringUnit_coulomb_metre = 4272694, /* C·m */
    EngineeringUnit_coulomb_metre_squared_per_volt = 4272695, /* C·m²/V */
    EngineeringUnit_coulomb_per_cubic_centimetre = 4272696, /* C/cm³ */
    EngineeringUnit_coulomb_per_cubic_metre = 4272697, /* C/m³ */
    EngineeringUnit_ampere_per_millimetre = 16691, /* A/mm */
    EngineeringUnit_coulomb_per_cubic_millimetre = 4272944, /* C/mm³ */
    EngineeringUnit_coulomb_per_kilogram_second = 4272945, /* C/(kg·s) */
    EngineeringUnit_coulomb_per_mole = 4272946, /* C/mol */
    EngineeringUnit_coulomb_per_square_centimetre = 4272947, /* C/cm² */
    EngineeringUnit_coulomb_per_square_metre = 4272948, /* C/m² */
    EngineeringUnit_coulomb_per_square_millimetre = 4272949, /* C/mm² */
    EngineeringUnit_cubic_centimetre_per_mole = 4272950, /* cm³/mol */
    EngineeringUnit_cubic_decimetre_per_mole = 4272951, /* dm³/mol */
    EngineeringUnit_cubic_metre_per_coulomb = 4272952, /* m³/C */
    EngineeringUnit_cubic_metre_per_kilogram = 4272953, /* m³/kg */
    EngineeringUnit_ampere_per_square_centimetre = 16692, /* A/cm² */
    EngineeringUnit_cubic_metre_per_mole = 4273200, /* m³/mol */
    EngineeringUnit_ampere_per_square_metre = 4273201, /* A/m² */
    EngineeringUnit_curie_per_kilogram = 4273202, /* Ci/kg */
    EngineeringUnit_deadweight_tonnage = 4273203, /* dwt */
    EngineeringUnit_decalitre = 4273204, /* dal */
    EngineeringUnit_decametre = 4273205, /* dam */
    EngineeringUnit_decitex = 4273207, /* dtex (g/10km) */
    EngineeringUnit_degree_Rankine = 4273208, /* °R */
    EngineeringUnit_denier = 4273209, /* den (g/9 km) */
    EngineeringUnit_ampere_square_metre = 16693, /* A·m² */
    EngineeringUnit_dyne_second_per_cubic_centimetre = 4273456, /* dyn·s/cm³ */
    EngineeringUnit_dyne_second_per_centimetre = 4273457, /* dyn·s/cm */
    EngineeringUnit_dyne_second_per_centimetre_to_the_fifth_power = 4273458, /* dyn·s/cm5 */
    EngineeringUnit_electronvolt = 4273459, /* eV */
    EngineeringUnit_electronvolt_per_metre = 4273460, /* eV/m */
    EngineeringUnit_electronvolt_square_metre = 4273461, /* eV·m² */
    EngineeringUnit_electronvolt_square_metre_per_kilogram = 4273462, /* eV·m²/kg */
    EngineeringUnit_erg = 4273463, /* erg */
    EngineeringUnit_erg_per_centimetre = 4273464, /* erg/cm */
    EngineeringUnit_S8_part_cloud_cover = 4273465, /*  */
    EngineeringUnit_ampere_per_square_metre_kelvin_squared = 16694, /* A/(m²·K²) */
    EngineeringUnit_erg_per_cubic_centimetre = 4273712, /* erg/cm³ */
    EngineeringUnit_erg_per_gram = 4273713, /* erg/g */
    EngineeringUnit_erg_per_gram_second = 4273714, /* erg/g·s */
    EngineeringUnit_erg_per_second = 4273715, /* erg/s */
    EngineeringUnit_erg_per_second_square_centimetre = 4273716, /* erg/(s·cm²) */
    EngineeringUnit_erg_per_square_centimetre_second = 4273717, /* erg/(cm²·s) */
    EngineeringUnit_erg_square_centimetre = 4273718, /* erg·cm² */
    EngineeringUnit_erg_square_centimetre_per_gram = 4273719, /* erg·cm²/g */
    EngineeringUnit_exajoule = 4273720, /* EJ */
    EngineeringUnit_farad_per_metre = 4273721, /* F/m */
    EngineeringUnit_ampere_per_square_millimetre = 16695, /* A/mm² */
    EngineeringUnit_femtojoule = 4273968, /* fJ */
    EngineeringUnit_femtometre = 4273969, /* fm */
    EngineeringUnit_foot_per_second_squared = 4273971, /* ft/s² */
    EngineeringUnit_foot_pound_force_per_second = 4273972, /* ft·lbf/s */
    EngineeringUnit_freight_ton = 4273973, /*  */
    EngineeringUnit_gal = 4273974, /* Gal */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_displacement = 4273975, /*  */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_electric_current = 4273976, /*  */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_electric_charge = 4273977, /*  */
    EngineeringUnit_ampere_second = 16696, /* A·s */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_electric_field_strength = 4274224, /*  */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_electric_polarization = 4274225, /*  */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_electric_potential = 4274226, /*  */
    EngineeringUnit_Gaussian_CGS__Centimetre_Gram_Second_system__unit_of_magnetization = 4274227, /*  */
    EngineeringUnit_gigacoulomb_per_cubic_metre = 4274228, /* GC/m³ */
    EngineeringUnit_gigaelectronvolt = 4274229, /* GeV */
    EngineeringUnit_gigahertz = 4274230, /* GHz */
    EngineeringUnit_gigaohm = 4274231, /* G? */
    EngineeringUnit_gigaohm_metre = 4274232, /* G?·m */
    EngineeringUnit_gigapascal = 4274233, /* GPa */
    EngineeringUnit_rate = 16697, /*  */
    EngineeringUnit_gigawatt = 4274480, /* GW */
    EngineeringUnit_grade = 4274481, /*  */
    EngineeringUnit_gram_per_cubic_metre = 4274483, /* g/m³ */
    EngineeringUnit_gram_per_mole = 4274484, /* g/mol */
    EngineeringUnit_gray = 4274485, /* Gy */
    EngineeringUnit_gray_per_second = 4274486, /* Gy/s */
    EngineeringUnit_hectopascal = 4274487, /* hPa */
    EngineeringUnit_henry_per_metre = 4274488, /* H/m */
    EngineeringUnit_bit = 4274489, /* bit */
    EngineeringUnit_ball = 16705, /*  */
    EngineeringUnit_bulk_pack = 16706, /* pk */
    EngineeringUnit_acre = 4277074, /* acre */
    EngineeringUnit_activity = 4277076, /*  */
    EngineeringUnit_Byte = 16708, /* byte */
    EngineeringUnit_ampere_per_metre = 16709, /* A/m */
    EngineeringUnit_additional_minute = 16712, /*  */
    EngineeringUnit_average_minute_per_call = 16713, /*  */
    EngineeringUnit_fathom = 16715, /* fth */
    EngineeringUnit_access_line = 16716, /*  */
    EngineeringUnit_ampere_hour = 4279624, /* A·h */
    EngineeringUnit_ampere = 4279632, /* A */
    EngineeringUnit_year = 4279886, /* y */
    EngineeringUnit_troy_ounce_or_apothecary_ounce = 4280410, /* tr oz */
    EngineeringUnit_anti_hemophilic_factor__AHF__unit = 16721, /*  */
    EngineeringUnit_are = 4280901, /* a */
    EngineeringUnit_assortment = 16723, /*  */
    EngineeringUnit_alcoholic_strength_by_mass = 4281165, /*  */
    EngineeringUnit_alcoholic_strength_by_volume = 4281173, /*  */
    EngineeringUnit_standard_atmosphere = 4281421, /* atm */
    EngineeringUnit_technical_atmosphere = 4281428, /* at */
    EngineeringUnit_assembly = 16729, /*  */
    EngineeringUnit_British_thermal_unit__international_table__per_pound = 16730, /* BtuIT/lb */
    EngineeringUnit_barrel__US__per_day = 16945, /* barrel (US)/d */
    EngineeringUnit_bit_per_second = 4337968, /* bit/s */
    EngineeringUnit_joule_per_kilogram_kelvin = 4337969, /* J/(kg·K) */
    EngineeringUnit_joule_per_metre = 4337970, /* J/m */
    EngineeringUnit_joule_per_square_metre = 4337971, /* J/m² */
    EngineeringUnit_joule_per_metre_to_the_fourth_power = 4337972, /* J/m4 */
    EngineeringUnit_joule_per_mole = 4337973, /* J/mol */
    EngineeringUnit_joule_per_mole_kelvin = 4337974, /* J/(mol·K) */
    EngineeringUnit_credit = 4337975, /*  */
    EngineeringUnit_joule_second = 4337976, /* J·s */
    EngineeringUnit_digit = 4337977, /*  */
    EngineeringUnit_joule_square_metre_per_kilogram = 4338224, /* J·m²/kg */
    EngineeringUnit_kelvin_per_watt = 4338225, /* K/W */
    EngineeringUnit_kiloampere = 4338226, /* kA */
    EngineeringUnit_kiloampere_per_square_metre = 4338227, /* kA/m² */
    EngineeringUnit_kiloampere_per_metre = 4338228, /* kA/m */
    EngineeringUnit_kilobecquerel_per_kilogram = 4338229, /* kBq/kg */
    EngineeringUnit_kilocoulomb = 4338230, /* kC */
    EngineeringUnit_kilocoulomb_per_cubic_metre = 4338231, /* kC/m³ */
    EngineeringUnit_kilocoulomb_per_square_metre = 4338232, /* kC/m² */
    EngineeringUnit_kiloelectronvolt = 4338233, /* keV */
    EngineeringUnit_batting_pound = 16947, /*  */
    EngineeringUnit_gibibit = 4338480, /* Gibit */
    EngineeringUnit_kilogram_metre_per_second = 4338481, /* kg·m/s */
    EngineeringUnit_kilogram_metre_squared = 4338482, /* kg·m² */
    EngineeringUnit_kilogram_metre_squared_per_second = 4338483, /* kg·m²/s */
    EngineeringUnit_kilogram_per_cubic_decimetre = 4338484, /* kg/dm³ */
    EngineeringUnit_kilogram_per_litre = 4338485, /* kg/l or kg/L */
    EngineeringUnit_calorie__thermochemical__per_gram = 4338486, /* calth/g */
    EngineeringUnit_kilogram_force = 4338487, /* kgf */
    EngineeringUnit_kilogram_force_metre = 4338488, /* kgf·m */
    EngineeringUnit_kilogram_force_metre_per_second = 4338489, /* kgf·m/s */
    EngineeringUnit_barrel__imperial = 16948, /*  */
    EngineeringUnit_kilogram_force_per_square_metre = 4338736, /* kgf/m² */
    EngineeringUnit_kilojoule_per_kelvin = 4338737, /* kJ/K */
    EngineeringUnit_kilojoule_per_kilogram = 4338738, /* kJ/kg */
    EngineeringUnit_kilojoule_per_kilogram_kelvin = 4338739, /* kJ/(kg·K) */
    EngineeringUnit_kilojoule_per_mole = 4338740, /* kJ/mol */
    EngineeringUnit_kilomole = 4338741, /* kmol */
    EngineeringUnit_kilomole_per_cubic_metre = 4338742, /* kmol/m³ */
    EngineeringUnit_kilonewton = 4338743, /* kN */
    EngineeringUnit_kilonewton_metre = 4338744, /* kN·m */
    EngineeringUnit_kiloohm = 4338745, /* k? */
    EngineeringUnit_kiloohm_metre = 4338992, /* k?·m */
    EngineeringUnit_kilopond = 4338993, /* kp */
    EngineeringUnit_kilosecond = 4338994, /* ks */
    EngineeringUnit_kilosiemens = 4338995, /* kS */
    EngineeringUnit_kilosiemens_per_metre = 4338996, /* kS/m */
    EngineeringUnit_kilovolt_per_metre = 4338997, /* kV/m */
    EngineeringUnit_kiloweber_per_metre = 4338998, /* kWb/m */
    EngineeringUnit_light_year = 4338999, /* ly */
    EngineeringUnit_litre_per_mole = 4339000, /* l/mol */
    EngineeringUnit_lumen_hour = 4339001, /* lm·h */
    EngineeringUnit_lumen_per_square_metre = 4339248, /* lm/m² */
    EngineeringUnit_lumen_per_watt = 4339249, /* lm/W */
    EngineeringUnit_lumen_second = 4339250, /* lm·s */
    EngineeringUnit_lux_hour = 4339251, /* lx·h */
    EngineeringUnit_lux_second = 4339252, /* lx·s */
    EngineeringUnit_maxwell = 4339253, /* Mx */
    EngineeringUnit_megaampere_per_square_metre = 4339254, /* MA/m² */
    EngineeringUnit_megabecquerel_per_kilogram = 4339255, /* MBq/kg */
    EngineeringUnit_gigabit = 4339256, /* Gbit */
    EngineeringUnit_megacoulomb_per_cubic_metre = 4339257, /* MC/m³ */
    EngineeringUnit_cycle = 16951, /*  */
    EngineeringUnit_megacoulomb_per_square_metre = 4339504, /* MC/m² */
    EngineeringUnit_megaelectronvolt = 4339505, /* MeV */
    EngineeringUnit_megagram_per_cubic_metre = 4339506, /* Mg/m³ */
    EngineeringUnit_meganewton = 4339507, /* MN */
    EngineeringUnit_meganewton_metre = 4339508, /* MN·m */
    EngineeringUnit_megaohm = 4339509, /* M? */
    EngineeringUnit_megaohm_metre = 4339510, /* M?·m */
    EngineeringUnit_megasiemens_per_metre = 4339511, /* MS/m */
    EngineeringUnit_megavolt = 4339512, /* MV */
    EngineeringUnit_megavolt_per_metre = 4339513, /* MV/m */
    EngineeringUnit_joule_per_cubic_metre = 16952, /* J/m³ */
    EngineeringUnit_gigabit_per_second = 4339760, /* Gbit/s */
    EngineeringUnit_reciprocal_metre_squared_reciprocal_second = 4339761, /* m?²/s */
    EngineeringUnit_inch_per_linear_foot = 4339762, /*  */
    EngineeringUnit_metre_to_the_fourth_power = 4339763, /* m4 */
    EngineeringUnit_microampere = 4339764, /* µA */
    EngineeringUnit_microbar = 4339765, /* µbar */
    EngineeringUnit_microcoulomb = 4339766, /* µC */
    EngineeringUnit_microcoulomb_per_cubic_metre = 4339767, /* µC/m³ */
    EngineeringUnit_microcoulomb_per_square_metre = 4339768, /* µC/m² */
    EngineeringUnit_microfarad_per_metre = 4339769, /* µF/m */
    EngineeringUnit_microhenry = 4340016, /* µH */
    EngineeringUnit_microhenry_per_metre = 4340017, /* µH/m */
    EngineeringUnit_micronewton = 4340018, /* µN */
    EngineeringUnit_micronewton_metre = 4340019, /* µN·m */
    EngineeringUnit_microohm = 4340020, /* µ? */
    EngineeringUnit_microohm_metre = 4340021, /* µ?·m */
    EngineeringUnit_micropascal = 4340022, /* µPa */
    EngineeringUnit_microradian = 4340023, /* µrad */
    EngineeringUnit_microsecond = 4340024, /* µs */
    EngineeringUnit_microsiemens = 4340025, /* µS */
    EngineeringUnit_bar__unit_of_pressure_ = 4342098, /* bar */
    EngineeringUnit_base_box = 16962, /*  */
    EngineeringUnit_board_foot = 4343380, /* fbm */
    EngineeringUnit_brake_horse_power = 4343888, /* BHP */
    EngineeringUnit_billion__EUR_ = 4344140, /*  */
    EngineeringUnit_dry_barrel__US_ = 4344900, /* bbl (US) */
    EngineeringUnit_barrel__US_ = 4344908, /* barrel (US) */
    EngineeringUnit_hundred_board_foot = 16976, /*  */
    EngineeringUnit_becquerel = 4346188, /* Bq */
    EngineeringUnit_British_thermal_unit__international_table_ = 4346965, /* BtuIT */
    EngineeringUnit_bushel__US_ = 4347201, /* bu (US) */
    EngineeringUnit_bushel__UK_ = 4347209, /* bushel (UK) */
    EngineeringUnit_call = 17200, /*  */
    EngineeringUnit_millifarad = 4403504, /* mF */
    EngineeringUnit_milligal = 4403505, /* mGal */
    EngineeringUnit_milligram_per_metre = 4403506, /* mg/m */
    EngineeringUnit_milligray = 4403507, /* mGy */
    EngineeringUnit_millihenry = 4403508, /* mH */
    EngineeringUnit_millijoule = 4403509, /* mJ */
    EngineeringUnit_millimetre_per_second = 4403510, /* mm/s */
    EngineeringUnit_millimetre_squared_per_second = 4403511, /* mm²/s */
    EngineeringUnit_millimole = 4403512, /* mmol */
    EngineeringUnit_mole_per_kilogram = 4403513, /* mol/kg */
    EngineeringUnit_millinewton = 4403760, /* mN */
    EngineeringUnit_kibibit = 4403761, /* Kibit */
    EngineeringUnit_millinewton_per_metre = 4403762, /* mN/m */
    EngineeringUnit_milliohm_metre = 4403763, /* m?·m */
    EngineeringUnit_millipascal_second = 4403764, /* mPa·s */
    EngineeringUnit_milliradian = 4403765, /* mrad */
    EngineeringUnit_millisecond = 4403766, /* ms */
    EngineeringUnit_millisiemens = 4403767, /* mS */
    EngineeringUnit_millisievert = 4403768, /* mSv */
    EngineeringUnit_millitesla = 4403769, /* mT */
    EngineeringUnit_microvolt_per_metre = 17203, /* µV/m */
    EngineeringUnit_millivolt_per_metre = 4404016, /* mV/m */
    EngineeringUnit_milliwatt = 4404017, /* mW */
    EngineeringUnit_milliwatt_per_square_metre = 4404018, /* mW/m² */
    EngineeringUnit_milliweber = 4404019, /* mWb */
    EngineeringUnit_mole = 4404020, /* mol */
    EngineeringUnit_mole_per_cubic_decimetre = 4404021, /* mol/dm³ */
    EngineeringUnit_mole_per_cubic_metre = 4404022, /* mol/m³ */
    EngineeringUnit_kilobit = 4404023, /* kbit */
    EngineeringUnit_mole_per_litre = 4404024, /* mol/l */
    EngineeringUnit_nanoampere = 4404025, /* nA */
    EngineeringUnit_nanocoulomb = 4404272, /* nC */
    EngineeringUnit_nanofarad = 4404273, /* nF */
    EngineeringUnit_nanofarad_per_metre = 4404274, /* nF/m */
    EngineeringUnit_nanohenry = 4404275, /* nH */
    EngineeringUnit_nanohenry_per_metre = 4404276, /* nH/m */
    EngineeringUnit_nanometre = 4404277, /* nm */
    EngineeringUnit_nanoohm_metre = 4404278, /* n?·m */
    EngineeringUnit_nanosecond = 4404279, /* ns */
    EngineeringUnit_nanotesla = 4404280, /* nT */
    EngineeringUnit_nanowatt = 4404281, /* nW */
    EngineeringUnit_neper = 4404528, /* Np */
    EngineeringUnit_neper_per_second = 4404529, /* Np/s */
    EngineeringUnit_picometre = 4404530, /* pm */
    EngineeringUnit_newton_metre_second = 4404531, /* N·m·s */
    EngineeringUnit_newton_metre_squared_per_kilogram_squared = 4404532, /* N·m²/kg² */
    EngineeringUnit_newton_per_square_metre = 4404533, /* N/m² */
    EngineeringUnit_newton_per_square_millimetre = 4404534, /* N/mm² */
    EngineeringUnit_newton_second = 4404535, /* N·s */
    EngineeringUnit_newton_second_per_metre = 4404536, /* N·s/m */
    EngineeringUnit_octave = 4404537, /*  */
    EngineeringUnit_ohm_centimetre = 4404784, /* ?·cm */
    EngineeringUnit_ohm_metre = 4404785, /* ?·m */
    EngineeringUnit_one = 4404786, /* 1 */
    EngineeringUnit_parsec = 4404787, /* pc */
    EngineeringUnit_pascal_per_kelvin = 4404788, /* Pa/K */
    EngineeringUnit_pascal_second = 4404789, /* Pa·s */
    EngineeringUnit_pascal_second_per_cubic_metre = 4404790, /* Pa·s/m³ */
    EngineeringUnit_pascal_second_per_metre = 4404791, /* Pa· s/m */
    EngineeringUnit_petajoule = 4404792, /* PJ */
    EngineeringUnit_phon = 4404793, /*  */
    EngineeringUnit_centipoise = 17207, /* cP */
    EngineeringUnit_picoampere = 4405040, /* pA */
    EngineeringUnit_picocoulomb = 4405041, /* pC */
    EngineeringUnit_picofarad_per_metre = 4405042, /* pF/m */
    EngineeringUnit_picohenry = 4405043, /* pH */
    EngineeringUnit_kilobit_per_second = 4405044, /* kbit/s */
    EngineeringUnit_picowatt = 4405045, /* pW */
    EngineeringUnit_picowatt_per_square_metre = 4405046, /* pW/m² */
    EngineeringUnit_pound_force = 4405048, /* lbf */
    EngineeringUnit_kilovolt_ampere_hour = 4405049, /* kVAh */
    EngineeringUnit_millicoulomb_per_kilogram = 17208, /* mC/kg */
    EngineeringUnit_rad = 4405296, /* rad */
    EngineeringUnit_radian = 4405297, /* rad */
    EngineeringUnit_radian_square_metre_per_mole = 4405298, /* rad·m²/mol */
    EngineeringUnit_radian_square_metre_per_kilogram = 4405299, /* rad·m²/kg */
    EngineeringUnit_radian_per_metre = 4405300, /* rad/m */
    EngineeringUnit_reciprocal_angstrom = 4405301, /* Å?¹ */
    EngineeringUnit_reciprocal_cubic_metre = 4405302, /* m?³ */
    EngineeringUnit_reciprocal_cubic_metre_per_second = 4405303, /* m?³/s */
    EngineeringUnit_reciprocal_electron_volt_per_cubic_metre = 4405304, /* eV?¹/m³ */
    EngineeringUnit_reciprocal_henry = 4405305, /* H?¹ */
    EngineeringUnit_coil_group = 17209, /*  */
    EngineeringUnit_reciprocal_joule_per_cubic_metre = 4405552, /* J?¹/m³ */
    EngineeringUnit_reciprocal_kelvin_or_kelvin_to_the_power_minus_one = 4405553, /* K?¹ */
    EngineeringUnit_reciprocal_metre = 4405554, /* m?¹ */
    EngineeringUnit_reciprocal_square_metre = 4405555, /* m?² */
    EngineeringUnit_reciprocal_minute = 4405556, /* min?¹ */
    EngineeringUnit_reciprocal_mole = 4405557, /* mol?¹ */
    EngineeringUnit_reciprocal_pascal_or_pascal_to_the_power_minus_one = 4405558, /* Pa?¹ */
    EngineeringUnit_reciprocal_second = 4405559, /* s?¹ */
    EngineeringUnit_reciprocal_second_per_metre_squared = 4405561, /* s?¹/m² */
    EngineeringUnit_carrying_capacity_in_metric_ton = 4408148, /*  */
    EngineeringUnit_candela = 4408396, /* cd */
    EngineeringUnit_degree_Celsius = 4408652, /* °C */
    EngineeringUnit_hundred = 4408654, /*  */
    EngineeringUnit_card = 17223, /*  */
    EngineeringUnit_centigram = 4409165, /* cg */
    EngineeringUnit_coulomb_per_kilogram = 4410183, /* C/kg */
    EngineeringUnit_hundred_leave = 4410438, /*  */
    EngineeringUnit_centilitre = 4410452, /* cl */
    EngineeringUnit_square_centimetre = 4410699, /* cm² */
    EngineeringUnit_cubic_centimetre = 4410705, /* cm³ */
    EngineeringUnit_centimetre = 4410708, /* cm */
    EngineeringUnit_hundred_pack = 4410960, /*  */
    EngineeringUnit_cental__UK_ = 4410964, /*  */
    EngineeringUnit_coulomb = 4411221, /* C */
    EngineeringUnit_content_gram = 4412487, /*  */
    EngineeringUnit_metric_carat = 4412493, /*  */
    EngineeringUnit_content_ton__metric_ = 4412494, /*  */
    EngineeringUnit_curie = 4412754, /* Ci */
    EngineeringUnit_hundred_pound__cwt____hundred_weight__US_ = 4413249, /* cwt (US) */
    EngineeringUnit_hundred_weight__UK_ = 4413257, /* cwt (UK) */
    EngineeringUnit_kilowatt_hour_per_hour = 4468787, /* kW·h/h */
    EngineeringUnit_lot___unit_of_weight_ = 4468788, /*  */
    EngineeringUnit_reciprocal_second_per_steradian = 17457, /* s?¹/sr */
    EngineeringUnit_siemens_per_metre = 4469040, /* S/m */
    EngineeringUnit_mebibit = 4469041, /* Mibit */
    EngineeringUnit_siemens_square_metre_per_mole = 4469042, /* S·m²/mol */
    EngineeringUnit_sievert = 4469043, /* Sv */
    EngineeringUnit_sone = 4469045, /*  */
    EngineeringUnit_square_centimetre_per_erg = 4469046, /* cm²/erg */
    EngineeringUnit_square_centimetre_per_steradian_erg = 4469047, /* cm²/(sr·erg) */
    EngineeringUnit_metre_kelvin = 4469048, /* m·K */
    EngineeringUnit_square_metre_kelvin_per_watt = 4469049, /* m²·K/W */
    EngineeringUnit_reciprocal_second_per_steradian_metre_squared = 17458, /* s?¹/(sr·m²) */
    EngineeringUnit_square_metre_per_joule = 4469296, /* m²/J */
    EngineeringUnit_square_metre_per_kilogram = 4469297, /* m²/kg */
    EngineeringUnit_square_metre_per_mole = 4469298, /* m²/mol */
    EngineeringUnit_pen_gram__protein_ = 4469299, /*  */
    EngineeringUnit_square_metre_per_steradian = 4469300, /* m²/sr */
    EngineeringUnit_square_metre_per_steradian_joule = 4469301, /* m²/(sr·J) */
    EngineeringUnit_square_metre_per_volt_second = 4469302, /* m²/(V·s) */
    EngineeringUnit_steradian = 4469303, /* sr */
    EngineeringUnit_terahertz = 4469305, /* THz */
    EngineeringUnit_terajoule = 4469552, /* TJ */
    EngineeringUnit_terawatt = 4469553, /* TW */
    EngineeringUnit_terawatt_hour = 4469554, /* TW·h */
    EngineeringUnit_tesla = 4469555, /* T */
    EngineeringUnit_tex = 4469556, /* tex (g/km) */
    EngineeringUnit_calorie__thermochemical_ = 4469557, /* calth */
    EngineeringUnit_megabit = 4469558, /* Mbit */
    EngineeringUnit_calorie__thermochemical__per_gram_kelvin = 4469559, /* calth/(g·K) */
    EngineeringUnit_calorie__thermochemical__per_second_centimetre_kelvin = 4469560, /* calth/(s·cm·K) */
    EngineeringUnit_calorie__thermochemical__per_second_square_centimetre_kelvin = 4469561, /* calth/(s·cm²·K) */
    EngineeringUnit_tonne_per_cubic_metre = 4469809, /* t/m³ */
    EngineeringUnit_tropical_year = 4469810, /* y (tropical) */
    EngineeringUnit_unified_atomic_mass_unit = 4469811, /* u */
    EngineeringUnit_var = 4469812, /* var */
    EngineeringUnit_volt_squared_per_kelvin_squared = 4469813, /* V²/K² */
    EngineeringUnit_volt___ampere = 4469814, /* V·A */
    EngineeringUnit_volt_per_centimetre = 4469815, /* V/cm */
    EngineeringUnit_volt_per_kelvin = 4469816, /* V/K */
    EngineeringUnit_millivolt_per_kelvin = 4469817, /* mV/K */
    EngineeringUnit_kilogram_per_square_centimetre = 17461, /* kg/cm² */
    EngineeringUnit_volt_per_metre = 4470064, /* V/m */
    EngineeringUnit_volt_per_millimetre = 4470065, /* V/mm */
    EngineeringUnit_watt_per_kelvin = 4470066, /* W/K */
    EngineeringUnit_watt_per_metre_kelvin = 4470067, /* W/(m·K) */
    EngineeringUnit_watt_per_square_metre = 4470068, /* W/m² */
    EngineeringUnit_watt_per_square_metre_kelvin = 4470069, /* W/(m²·K) */
    EngineeringUnit_watt_per_square_metre_kelvin_to_the_fourth_power = 4470070, /* W/(m²·K4) */
    EngineeringUnit_watt_per_steradian = 4470071, /* W/sr */
    EngineeringUnit_watt_per_steradian_square_metre = 4470072, /* W/(sr·m²) */
    EngineeringUnit_weber_per_metre = 4470073, /* Wb/m */
    EngineeringUnit_roentgen_per_second = 17462, /* R/s */
    EngineeringUnit_weber_per_millimetre = 4470320, /* Wb/mm */
    EngineeringUnit_minute__unit_of_angle_ = 4470321, /* ' */
    EngineeringUnit_second__unit_of_angle_ = 4470322, /* " */
    EngineeringUnit_book = 4470323, /*  */
    EngineeringUnit_round = 4470325, /*  */
    EngineeringUnit_number_of_words = 4470328, /*  */
    EngineeringUnit_inch_to_the_fourth_power = 4470329, /* in4 */
    EngineeringUnit_calorie__international_table__ = 4470576, /* calIT */
    EngineeringUnit_calorie__international_table__per_second_centimetre_kelvin = 4470577, /* calIT/(s·cm·K) */
    EngineeringUnit_calorie__international_table__per_second_square_centimetre_kelvin = 4470578, /* calIT/(s·cm²·K) */
    EngineeringUnit_joule_square_metre = 4470579, /* J·m² */
    EngineeringUnit_kilogram_per_mole = 4470580, /* kg/mol */
    EngineeringUnit_calorie__international_table__per_gram = 4470581, /* calIT/g */
    EngineeringUnit_calorie__international_table__per_gram_kelvin = 4470582, /* calIT/(g·K) */
    EngineeringUnit_megacoulomb = 4470583, /* MC */
    EngineeringUnit_megajoule_per_second = 4470584, /* MJ/s */
    EngineeringUnit_microwatt = 4470832, /* µW */
    EngineeringUnit_microtesla = 4470833, /* µT */
    EngineeringUnit_microvolt = 4470834, /* µV */
    EngineeringUnit_millinewton_metre = 4470835, /* mN·m */
    EngineeringUnit_microwatt_per_square_metre = 4470837, /* µW/m² */
    EngineeringUnit_millicoulomb = 4470838, /* mC */
    EngineeringUnit_millimole_per_kilogram = 4470839, /* mmol/kg */
    EngineeringUnit_millicoulomb_per_cubic_metre = 4470840, /* mC/m³ */
    EngineeringUnit_millicoulomb_per_square_metre = 4470841, /* mC/m² */
    EngineeringUnit_dyne_per_square_centimetre = 17465, /* dyn/cm² */
    EngineeringUnit_rem = 4471089, /* rem */
    EngineeringUnit_second_per_cubic_metre = 4471091, /* s/m³ */
    EngineeringUnit_second_per_cubic_metre_radian = 4471092, /* s/(rad·m³) */
    EngineeringUnit_joule_per_gram = 4471093, /* J/g */
    EngineeringUnit_decare = 4473153, /* daa */
    EngineeringUnit_ten_day = 4473156, /*  */
    EngineeringUnit_day = 4473177, /* d */
    EngineeringUnit_dry_pound = 17474, /*  */
    EngineeringUnit_degree__unit_of_angle_ = 17476, /* ° */
    EngineeringUnit_decade = 4474179, /*  */
    EngineeringUnit_decigram = 17479, /* dg */
    EngineeringUnit_decagram = 17482, /* dag */
    EngineeringUnit_decilitre = 4475988, /* dl */
    EngineeringUnit_cubic_decametre = 4476225, /* dam³ */
    EngineeringUnit_square_decimetre = 4476235, /* dm² */
    EngineeringUnit_standard_kilolitre = 4476239, /*  */
    EngineeringUnit_cubic_decimetre = 4476241, /* dm³ */
    EngineeringUnit_decimetre = 4476244, /* dm */
    EngineeringUnit_decinewton_metre = 17486, /* dN·m */
    EngineeringUnit_dozen_piece = 4476995, /*  */
    EngineeringUnit_dozen_pair = 4477010, /*  */
    EngineeringUnit_displacement_tonnage = 4477012, /*  */
    EngineeringUnit_dram__US_ = 4477505, /*  */
    EngineeringUnit_dram__UK_ = 4477513, /*  */
    EngineeringUnit_dozen_roll = 4477516, /*  */
    EngineeringUnit_dry_ton = 17492, /*  */
    EngineeringUnit_decitonne = 4478030, /* dt or dtn */
    EngineeringUnit_dyne = 17493, /* dyn */
    EngineeringUnit_pennyweight = 4478804, /*  */
    EngineeringUnit_dyne_per_centimetre = 17496, /* dyn/cm */
    EngineeringUnit_dozen = 4479566, /* DOZ */
    EngineeringUnit_dozen_pack = 4479568, /*  */
    EngineeringUnit_newton_per_square_centimetre = 4534321, /* N/cm² */
    EngineeringUnit_megawatt_hour_per_hour = 4534327, /* MW·h/h */
    EngineeringUnit_megawatt_per_hertz = 4534328, /* MW/Hz */
    EngineeringUnit_milliampere_hour = 4534329, /* mA·h */
    EngineeringUnit_degree_day = 4534576, /* deg da */
    EngineeringUnit_gigacalorie = 4534577, /*  */
    EngineeringUnit_mille = 4534578, /*  */
    EngineeringUnit_kilocalorie__international_table_ = 4534580, /* kcalIT */
    EngineeringUnit_kilocalorie__thermochemical__per_hour = 4534581, /* kcalth/h */
    EngineeringUnit_million_Btu_IT__per_hour = 4534582, /* BtuIT/h */
    EngineeringUnit_cubic_foot_per_second = 4534583, /* ft³/s */
    EngineeringUnit_tonne_per_hour = 4534584, /* t/h */
    EngineeringUnit_ping = 4534585, /*  */
    EngineeringUnit_megabit_per_second = 4534832, /* Mbit/s */
    EngineeringUnit_shares = 4534833, /*  */
    EngineeringUnit_TEU = 4534834, /*  */
    EngineeringUnit_tyre = 4534835, /*  */
    EngineeringUnit_active_unit = 4534837, /*  */
    EngineeringUnit_dose = 4534839, /*  */
    EngineeringUnit_air_dry_ton = 4534840, /*  */
    EngineeringUnit_strand = 4535088, /*  */
    EngineeringUnit_square_metre_per_litre = 4535089, /* m²/l */
    EngineeringUnit_litre_per_hour = 4535090, /* l/h */
    EngineeringUnit_foot_per_thousand = 4535091, /*  */
    EngineeringUnit_gigabyte = 4535092, /* Gbyte */
    EngineeringUnit_terabyte = 4535093, /* Tbyte */
    EngineeringUnit_petabyte = 4535094, /* Pbyte */
    EngineeringUnit_pixel = 4535095, /*  */
    EngineeringUnit_megapixel = 4535096, /*  */
    EngineeringUnit_dots_per_inch = 4535097, /* dpi */
    EngineeringUnit_gross_kilogram = 17716, /*  */
    EngineeringUnit_part_per_hundred_thousand = 4535344, /* ppht */
    EngineeringUnit_kilogram_force_per_square_millimetre = 4535345, /* kgf·m/cm² */
    EngineeringUnit_kilogram_force_per_square_centimetre = 4535346, /* kgf/cm² */
    EngineeringUnit_joule_per_square_centimetre = 4535347, /* J/cm² */
    EngineeringUnit_kilogram_force_metre_per_square_centimetre = 4535348, /* kgf·m/cm² */
    EngineeringUnit_milliohm = 4535349, /* m? */
    EngineeringUnit_kilowatt_hour_per_cubic_metre = 4535350, /* kW·h/m³ */
    EngineeringUnit_kilowatt_hour_per_kelvin = 4535351, /* kW·h/K */
    EngineeringUnit_service_unit = 4535352, /*  */
    EngineeringUnit_working_day = 4535353, /*  */
    EngineeringUnit_accounting_unit = 4535600, /*  */
    EngineeringUnit_job = 4535601, /*  */
    EngineeringUnit_run_foot = 4535602, /*  */
    EngineeringUnit_test = 4535603, /*  */
    EngineeringUnit_trip = 4535604, /*  */
    EngineeringUnit_use = 4535605, /*  */
    EngineeringUnit_well = 4535606, /*  */
    EngineeringUnit_zone = 4535607, /*  */
    EngineeringUnit_exabit_per_second = 4535608, /* Ebit/s */
    EngineeringUnit_exbibyte = 4535609, /* Eibyte */
    EngineeringUnit_pebibyte = 4535856, /* Pibyte */
    EngineeringUnit_tebibyte = 4535857, /* Tibyte */
    EngineeringUnit_gibibyte = 4535858, /* Gibyte */
    EngineeringUnit_mebibyte = 4535859, /* Mibyte */
    EngineeringUnit_kibibyte = 4535860, /* Kibyte */
    EngineeringUnit_exbibit_per_metre = 4535861, /* Eibit/m */
    EngineeringUnit_exbibit_per_square_metre = 4535862, /* Eibit/m² */
    EngineeringUnit_exbibit_per_cubic_metre = 4535863, /* Eibit/m³ */
    EngineeringUnit_gigabyte_per_second = 4535864, /* Gbyte/s */
    EngineeringUnit_gibibit_per_metre = 4535865, /* Gibit/m */
    EngineeringUnit_gibibit_per_square_metre = 4536112, /* Gibit/m² */
    EngineeringUnit_gibibit_per_cubic_metre = 4536113, /* Gibit/m³ */
    EngineeringUnit_kibibit_per_metre = 4536114, /* Kibit/m */
    EngineeringUnit_kibibit_per_square_metre = 4536115, /* Kibit/m² */
    EngineeringUnit_kibibit_per_cubic_metre = 4536116, /* Kibit/m³ */
    EngineeringUnit_mebibit_per_metre = 4536117, /* Mibit/m */
    EngineeringUnit_mebibit_per_square_metre = 4536118, /* Mibit/m² */
    EngineeringUnit_mebibit_per_cubic_metre = 4536119, /* Mibit/m³ */
    EngineeringUnit_petabit = 4536120, /* Pbit */
    EngineeringUnit_petabit_per_second = 4536121, /* Pbit/s */
    EngineeringUnit_pebibit_per_metre = 4536368, /* Pibit/m */
    EngineeringUnit_pebibit_per_square_metre = 4536369, /* Pibit/m² */
    EngineeringUnit_pebibit_per_cubic_metre = 4536370, /* Pibit/m³ */
    EngineeringUnit_terabit = 4536371, /* Tbit */
    EngineeringUnit_terabit_per_second = 4536372, /* Tbit/s */
    EngineeringUnit_tebibit_per_metre = 4536373, /* Tibit/m */
    EngineeringUnit_tebibit_per_cubic_metre = 4536374, /* Tibit/m³ */
    EngineeringUnit_tebibit_per_square_metre = 4536375, /* Tibit/m² */
    EngineeringUnit_bit_per_metre = 4536376, /* bit/m */
    EngineeringUnit_bit_per_square_metre = 4536377, /* bit/m² */
    EngineeringUnit_reciprocal_centimetre = 4536624, /* cm?¹ */
    EngineeringUnit_reciprocal_day = 4536625, /* d?¹ */
    EngineeringUnit_cubic_decimetre_per_hour = 4536626, /* dm³/h */
    EngineeringUnit_kilogram_per_hour = 4536627, /* kg/h */
    EngineeringUnit_kilomole_per_second = 4536628, /* kmol/s */
    EngineeringUnit_mole_per_second = 4536629, /* mol/s */
    EngineeringUnit_degree_per_second = 4536630, /* °/s */
    EngineeringUnit_millimetre_per_degree_Celcius_metre = 4536631, /* mm/(°C·m) */
    EngineeringUnit_degree_Celsius_per_kelvin = 4536632, /* °C/K */
    EngineeringUnit_hectopascal_per_bar = 4536633, /* hPa/bar */
    EngineeringUnit_each = 17729, /*  */
    EngineeringUnit_electronic_mail_box = 17730, /*  */
    EngineeringUnit_equivalent_gallon = 17745, /*  */
    EngineeringUnit_bit_per_cubic_metre = 4599857, /* bit/m³ */
    EngineeringUnit_kelvin_per_kelvin = 4599858, /* K/K */
    EngineeringUnit_kilopascal_per_bar = 4599859, /* kPa/bar */
    EngineeringUnit_millibar_per_bar = 4599860, /* mbar/bar */
    EngineeringUnit_megapascal_per_bar = 4599861, /* MPa/bar */
    EngineeringUnit_poise_per_bar = 4599862, /* P/bar */
    EngineeringUnit_pascal_per_bar = 4599863, /* Pa/bar */
    EngineeringUnit_milliampere_per_inch = 4599864, /* mA/in */
    EngineeringUnit_kelvin_per_hour = 4600112, /* K/h */
    EngineeringUnit_kelvin_per_minute = 4600113, /* K/min */
    EngineeringUnit_kelvin_per_second = 4600114, /* K/s */
    EngineeringUnit_slug = 4600115, /* slug */
    EngineeringUnit_gram_per_kelvin = 4600116, /* g/K */
    EngineeringUnit_kilogram_per_kelvin = 4600117, /* kg/K */
    EngineeringUnit_milligram_per_kelvin = 4600118, /* mg/K */
    EngineeringUnit_pound_force_per_foot = 4600119, /* lbf/ft */
    EngineeringUnit_kilogram_square_centimetre = 4600120, /* kg·cm² */
    EngineeringUnit_kilogram_square_millimetre = 4600121, /* kg·mm² */
    EngineeringUnit_pound_inch_squared = 4600368, /* lb·in² */
    EngineeringUnit_pound_force_inch = 4600369, /* lbf·in */
    EngineeringUnit_pound_force_foot_per_ampere = 4600370, /* lbf·ft/A */
    EngineeringUnit_gram_per_cubic_decimetre = 4600371, /* g/dm³ */
    EngineeringUnit_kilogram_per_kilomol = 4600372, /* kg/kmol */
    EngineeringUnit_gram_per_hertz = 4600373, /* g/Hz */
    EngineeringUnit_gram_per_day = 4600374, /* g/d */
    EngineeringUnit_gram_per_hour = 4600375, /* g/h */
    EngineeringUnit_gram_per_minute = 4600376, /* g/min */
    EngineeringUnit_gram_per_second = 4600377, /* g/s */
    EngineeringUnit_kilogram_per_day = 4600624, /* kg/d */
    EngineeringUnit_kilogram_per_minute = 4600625, /* kg/min */
    EngineeringUnit_milligram_per_day = 4600626, /* mg/d */
    EngineeringUnit_milligram_per_minute = 4600627, /* mg/min */
    EngineeringUnit_milligram_per_second = 4600628, /* mg/s */
    EngineeringUnit_gram_per_day_kelvin = 4600629, /* g/(d·K) */
    EngineeringUnit_gram_per_hour_kelvin = 4600630, /* g/(h·K) */
    EngineeringUnit_gram_per_minute_kelvin = 4600631, /* g/(min·K) */
    EngineeringUnit_gram_per_second_kelvin = 4600632, /* g/(s·K) */
    EngineeringUnit_kilogram_per_day_kelvin = 4600633, /* kg/(d·K) */
    EngineeringUnit_kilogram_per_hour_kelvin = 4600880, /* kg/(h·K) */
    EngineeringUnit_kilogram_per_minute_kelvin = 4600881, /* kg/(min·K) */
    EngineeringUnit_kilogram_per_second_kelvin = 4600882, /* kg/(s·K) */
    EngineeringUnit_milligram_per_day_kelvin = 4600883, /* mg/(d·K) */
    EngineeringUnit_milligram_per_hour_kelvin = 4600884, /* mg/(h·K) */
    EngineeringUnit_milligram_per_minute_kelvin = 4600885, /* mg/(min·K) */
    EngineeringUnit_milligram_per_second_kelvin = 4600886, /* mg/(s·K) */
    EngineeringUnit_newton_per_millimetre = 4600887, /* N/mm */
    EngineeringUnit_pound_force_per_inch = 4600888, /* lbf/in */
    EngineeringUnit_rod__unit_of_distance_ = 4600889, /* rd (US) */
    EngineeringUnit_micrometre_per_kelvin = 4601136, /* µm/K */
    EngineeringUnit_centimetre_per_kelvin = 4601137, /* cm/K */
    EngineeringUnit_metre_per_kelvin = 4601138, /* m/K */
    EngineeringUnit_millimetre_per_kelvin = 4601139, /* mm/K */
    EngineeringUnit_milliohm_per_metre = 4601140, /* m?/m */
    EngineeringUnit_ohm_per_mile__statute_mile_ = 4601141, /* ?/mi */
    EngineeringUnit_ohm_per_kilometre = 4601142, /* ?/km */
    EngineeringUnit_milliampere_per_pound_force_per_square_inch = 4601143, /* mA/(lbf/in²) */
    EngineeringUnit_reciprocal_bar = 4601144, /* 1/bar */
    EngineeringUnit_milliampere_per_bar = 4601145, /* mA/bar */
    EngineeringUnit_degree_Celsius_per_bar = 4601392, /* °C/bar */
    EngineeringUnit_kelvin_per_bar = 4601393, /* K/bar */
    EngineeringUnit_gram_per_day_bar = 4601394, /* g/(d·bar) */
    EngineeringUnit_gram_per_hour_bar = 4601395, /* g/(h·bar) */
    EngineeringUnit_gram_per_minute_bar = 4601396, /* g/(min·bar) */
    EngineeringUnit_gram_per_second_bar = 4601397, /* g/(s·bar) */
    EngineeringUnit_kilogram_per_day_bar = 4601398, /* kg/(d·bar) */
    EngineeringUnit_kilogram_per_hour_bar = 4601399, /* kg/(h·bar) */
    EngineeringUnit_kilogram_per_minute_bar = 4601400, /* kg/(min·bar) */
    EngineeringUnit_kilogram_per_second_bar = 4601401, /* kg/(s·bar) */
    EngineeringUnit_milligram_per_day_bar = 4601648, /* mg/(d·bar) */
    EngineeringUnit_milligram_per_hour_bar = 4601649, /* mg/(h·bar) */
    EngineeringUnit_milligram_per_minute_bar = 4601650, /* mg/(min·bar) */
    EngineeringUnit_milligram_per_second_bar = 4601651, /* mg/(s·bar) */
    EngineeringUnit_gram_per_bar = 4601652, /* g/bar */
    EngineeringUnit_milligram_per_bar = 4601653, /* mg/bar */
    EngineeringUnit_milliampere_per_millimetre = 4601654, /* mA/mm */
    EngineeringUnit_pascal_second_per_kelvin = 4601655, /* Pa.s/K */
    EngineeringUnit_inch_of_water = 4601656, /* inH2O */
    EngineeringUnit_inch_of_mercury = 4601657, /* inHg */
    EngineeringUnit_water_horse_power = 4601904, /*  */
    EngineeringUnit_bar_per_kelvin = 4601905, /* bar/K */
    EngineeringUnit_hectopascal_per_kelvin = 4601906, /* hPa/K */
    EngineeringUnit_kilopascal_per_kelvin = 4601907, /* kPa/K */
    EngineeringUnit_millibar_per_kelvin = 4601908, /* mbar/K */
    EngineeringUnit_megapascal_per_kelvin = 4601909, /* MPa/K */
    EngineeringUnit_poise_per_kelvin = 4601910, /* P/K */
    EngineeringUnit_volt_per_litre_minute = 4601911, /* V/(l·min) */
    EngineeringUnit_newton_centimetre = 4601912, /* N·cm */
    EngineeringUnit_newton_metre_per_degree = 4601913, /* Nm/° */
    EngineeringUnit_newton_metre_per_ampere = 4602160, /* N·m/A */
    EngineeringUnit_bar_litre_per_second = 4602161, /* bar·l/s */
    EngineeringUnit_bar_cubic_metre_per_second = 4602162, /* bar·m³/s */
    EngineeringUnit_hectopascal_litre_per_second = 4602163, /* hPa·l/s */
    EngineeringUnit_hectopascal_cubic_metre_per_second = 4602164, /* hPa·m³/s */
    EngineeringUnit_millibar_litre_per_second = 4602165, /* mbar·l/s */
    EngineeringUnit_millibar_cubic_metre_per_second = 4602166, /* mbar·m³/s */
    EngineeringUnit_megapascal_litre_per_second = 4602167, /* MPa·l/s */
    EngineeringUnit_megapascal_cubic_metre_per_second = 4602168, /* MPa·m³/s */
    EngineeringUnit_pascal_litre_per_second = 4602169, /* Pa·l/s */
    EngineeringUnit_degree_Fahrenheit = 4604232, /* °F */
    EngineeringUnit_farad = 4604242, /* F */
    EngineeringUnit_fibre_metre = 4604493, /*  */
    EngineeringUnit_thousand_cubic_foot = 17987, /* kft³ */
    EngineeringUnit_hundred_cubic_metre = 17990, /*  */
    EngineeringUnit_micromole = 17992, /* µmol */
    EngineeringUnit_failures_in_time = 4606292, /* FIT */
    EngineeringUnit_flake_ton = 17996, /*  */
    EngineeringUnit_foot = 4607828, /* ft */
    EngineeringUnit_pound_per_square_foot = 18000, /* lb/ft² */
    EngineeringUnit_foot_per_minute = 18002, /* ft/min */
    EngineeringUnit_foot_per_second = 18003, /* ft/s */
    EngineeringUnit_square_foot = 4609099, /* ft² */
    EngineeringUnit_cubic_foot = 4609105, /* ft³ */
    EngineeringUnit_pascal_cubic_metre_per_second = 4665393, /* Pa·m³/s */
    EngineeringUnit_centimetre_per_bar = 4665396, /* cm/bar */
    EngineeringUnit_metre_per_bar = 4665397, /* m/bar */
    EngineeringUnit_millimetre_per_bar = 4665398, /* mm/bar */
    EngineeringUnit_square_inch_per_second = 4665400, /* in²/s */
    EngineeringUnit_square_metre_per_second_kelvin = 4665401, /* m²/(s·K) */
    EngineeringUnit_stokes_per_kelvin = 4665648, /* St/K */
    EngineeringUnit_gram_per_cubic_centimetre_bar = 4665649, /* g/(cm³·bar) */
    EngineeringUnit_gram_per_cubic_decimetre_bar = 4665650, /* g/(dm³·bar) */
    EngineeringUnit_gram_per_litre_bar = 4665651, /* g/(l·bar) */
    EngineeringUnit_gram_per_cubic_metre_bar = 4665652, /* g/(m³·bar) */
    EngineeringUnit_gram_per_millilitre_bar = 4665653, /* g/(ml·bar) */
    EngineeringUnit_kilogram_per_cubic_centimetre_bar = 4665654, /* kg/(cm³·bar) */
    EngineeringUnit_kilogram_per_litre_bar = 4665655, /* kg/(l·bar) */
    EngineeringUnit_kilogram_per_cubic_metre_bar = 4665656, /* kg/(m³·bar) */
    EngineeringUnit_newton_metre_per_kilogram = 4665657, /* N·m/kg */
    EngineeringUnit_US_gallon_per_minute = 18226, /* gal (US) /min */
    EngineeringUnit_pound_force_foot_per_pound = 4665904, /* lbf·ft/lb */
    EngineeringUnit_cup__unit_of_volume_ = 4665905, /* cup (US) */
    EngineeringUnit_peck = 4665907, /* pk (US) */
    EngineeringUnit_tablespoon__US_ = 4665908, /* tablespoon (US) */
    EngineeringUnit_teaspoon__US_ = 4665909, /* teaspoon (US) */
    EngineeringUnit_stere = 4665910, /* st */
    EngineeringUnit_cubic_centimetre_per_kelvin = 4665911, /* cm³/K */
    EngineeringUnit_litre_per_kelvin = 4665912, /* l/K */
    EngineeringUnit_cubic_metre_per_kelvin = 4665913, /* m³/K */
    EngineeringUnit_Imperial_gallon_per_minute = 18227, /* gal (UK) /min */
    EngineeringUnit_millilitre_per_kelvin = 4666160, /* ml/K */
    EngineeringUnit_kilogram_per_cubic_centimetre = 4666161, /* kg/cm³ */
    EngineeringUnit_ounce__avoirdupois__per_cubic_yard = 4666162, /* oz/yd³ */
    EngineeringUnit_gram_per_cubic_centimetre_kelvin = 4666163, /* g/(cm³·K) */
    EngineeringUnit_gram_per_cubic_decimetre_kelvin = 4666164, /* g/(dm³·K) */
    EngineeringUnit_gram_per_litre_kelvin = 4666165, /* g/(l·K) */
    EngineeringUnit_gram_per_cubic_metre_kelvin = 4666166, /* g/(m³·K) */
    EngineeringUnit_gram_per_millilitre_kelvin = 4666167, /* g/(ml·K) */
    EngineeringUnit_kilogram_per_cubic_centimetre_kelvin = 4666168, /* kg/(cm³·K) */
    EngineeringUnit_kilogram_per_litre_kelvin = 4666169, /* kg/(l·K) */
    EngineeringUnit_kilogram_per_cubic_metre_kelvin = 4666416, /* kg/(m³·K) */
    EngineeringUnit_square_metre_per_second_bar = 4666417, /* m²/(s·bar) */
    EngineeringUnit_microsiemens_per_centimetre = 4666418, /* µS/cm */
    EngineeringUnit_microsiemens_per_metre = 4666419, /* µS/m */
    EngineeringUnit_nanosiemens_per_centimetre = 4666420, /* nS/cm */
    EngineeringUnit_nanosiemens_per_metre = 4666421, /* nS/m */
    EngineeringUnit_stokes_per_bar = 4666422, /* St/bar */
    EngineeringUnit_cubic_centimetre_per_day = 4666423, /* cm³/d */
    EngineeringUnit_cubic_centimetre_per_hour = 4666424, /* cm³/h */
    EngineeringUnit_cubic_centimetre_per_minute = 4666425, /* cm³/min */
    EngineeringUnit_gallon__US__per_hour = 4666672, /* gal/h */
    EngineeringUnit_litre_per_second = 4666673, /* l/s */
    EngineeringUnit_cubic_metre_per_day = 4666674, /* m³/d */
    EngineeringUnit_cubic_metre_per_minute = 4666675, /* m³/min */
    EngineeringUnit_millilitre_per_day = 4666676, /* ml/d */
    EngineeringUnit_millilitre_per_hour = 4666677, /* ml/h */
    EngineeringUnit_cubic_inch_per_hour = 4666678, /* in³/h */
    EngineeringUnit_cubic_inch_per_minute = 4666679, /* in³/min */
    EngineeringUnit_cubic_inch_per_second = 4666680, /* in³/s */
    EngineeringUnit_milliampere_per_litre_minute = 4666681, /* mA/(l·min) */
    EngineeringUnit_volt_per_bar = 4666928, /* V/bar */
    EngineeringUnit_cubic_centimetre_per_day_kelvin = 4666929, /* cm³/(d·K) */
    EngineeringUnit_cubic_centimetre_per_hour_kelvin = 4666930, /* cm³/(h·K) */
    EngineeringUnit_cubic_centimetre_per_minute_kelvin = 4666931, /* cm³/(min·K) */
    EngineeringUnit_cubic_centimetre_per_second_kelvin = 4666932, /* cm³/(s·K) */
    EngineeringUnit_litre_per_day_kelvin = 4666933, /* l/(d·K) */
    EngineeringUnit_litre_per_hour_kelvin = 4666934, /* l/(h·K) */
    EngineeringUnit_litre_per_minute_kelvin = 4666935, /* l/(min·K) */
    EngineeringUnit_litre_per_second_kelvin = 4666936, /* l/(s·K) */
    EngineeringUnit_cubic_metre_per_day_kelvin = 4666937, /* m³/(d·K) */
    EngineeringUnit_cubic_metre_per_hour_kelvin = 4667184, /* m³/(h·K) */
    EngineeringUnit_cubic_metre_per_minute_kelvin = 4667185, /* m³/(min·K) */
    EngineeringUnit_cubic_metre_per_second_kelvin = 4667186, /* m³/(s·K) */
    EngineeringUnit_millilitre_per_day_kelvin = 4667187, /* ml/(d·K) */
    EngineeringUnit_millilitre_per_hour_kelvin = 4667188, /* ml/(h·K) */
    EngineeringUnit_millilitre_per_minute_kelvin = 4667189, /* ml/(min·K) */
    EngineeringUnit_millilitre_per_second_kelvin = 4667190, /* ml/(s·K) */
    EngineeringUnit_millimetre_to_the_fourth_power = 4667191, /* mm4 */
    EngineeringUnit_cubic_centimetre_per_day_bar = 4667192, /* cm³/(d·bar) */
    EngineeringUnit_cubic_centimetre_per_hour_bar = 4667193, /* cm³/(h·bar) */
    EngineeringUnit_cubic_centimetre_per_minute_bar = 4667440, /* cm³/(min·bar) */
    EngineeringUnit_cubic_centimetre_per_second_bar = 4667441, /* cm³/(s·bar) */
    EngineeringUnit_litre_per_day_bar = 4667442, /* l/(d·bar) */
    EngineeringUnit_litre_per_hour_bar = 4667443, /* l/(h·bar) */
    EngineeringUnit_litre_per_minute_bar = 4667444, /* l/(min·bar) */
    EngineeringUnit_litre_per_second_bar = 4667445, /* l/(s·bar) */
    EngineeringUnit_cubic_metre_per_day_bar = 4667446, /* m³/(d·bar) */
    EngineeringUnit_cubic_metre_per_hour_bar = 4667447, /* m³/(h·bar) */
    EngineeringUnit_cubic_metre_per_minute_bar = 4667448, /* m³/(min·bar) */
    EngineeringUnit_cubic_metre_per_second_bar = 4667449, /* m³/(s·bar) */
    EngineeringUnit_millilitre_per_day_bar = 4667696, /* ml/(d·bar) */
    EngineeringUnit_millilitre_per_hour_bar = 4667697, /* ml/(h·bar) */
    EngineeringUnit_millilitre_per_minute_bar = 4667698, /* ml/(min·bar) */
    EngineeringUnit_millilitre_per_second_bar = 4667699, /* ml/(s·bar) */
    EngineeringUnit_cubic_centimetre_per_bar = 4667700, /* cm³/bar */
    EngineeringUnit_litre_per_bar = 4667701, /* l/bar */
    EngineeringUnit_cubic_metre_per_bar = 4667702, /* m³/bar */
    EngineeringUnit_millilitre_per_bar = 4667703, /* ml/bar */
    EngineeringUnit_microhenry_per_kiloohm = 4667704, /* µH/k? */
    EngineeringUnit_microhenry_per_ohm = 4667705, /* µH/? */
    EngineeringUnit_gallon__US__per_day = 18242, /* gal (US)/d */
    EngineeringUnit_gigabecquerel = 4670033, /* GBq */
    EngineeringUnit_gram__dry_weight = 4670551, /*  */
    EngineeringUnit_pound_per_gallon__US_ = 18245, /* lb/gal (US) */
    EngineeringUnit_gram_per_metre__gram_per_100_centimetres_ = 18246, /* g/m */
    EngineeringUnit_gram_of_fissile_isotope = 4671049, /* gi F/S */
    EngineeringUnit_great_gross = 4671314, /*  */
    EngineeringUnit_gill__US_ = 4671809, /* gi (US) */
    EngineeringUnit_gram__including_container = 4671811, /*  */
    EngineeringUnit_gill__UK_ = 4671817, /* gi (UK) */
    EngineeringUnit_gram__including_inner_packaging = 4671824, /*  */
    EngineeringUnit_gram_per_millilitre = 18250, /* g/ml */
    EngineeringUnit_gram_per_litre = 18252, /* g/l */
    EngineeringUnit_dry_gallon__US_ = 4672580, /* dry gal (US) */
    EngineeringUnit_gallon__UK_ = 4672585, /* gal (UK) */
    EngineeringUnit_gallon__US_ = 4672588, /* gal (US) */
    EngineeringUnit_gram_per_square_metre = 18253, /* g/m² */
    EngineeringUnit_milligram_per_square_metre = 18255, /* mg/m² */
    EngineeringUnit_milligram_per_cubic_metre = 18256, /* mg/m³ */
    EngineeringUnit_microgram_per_cubic_metre = 18257, /* µg/m³ */
    EngineeringUnit_gram = 4674125, /* g */
    EngineeringUnit_grain = 4674126, /* gr */
    EngineeringUnit_gross = 4674127, /* gr */
    EngineeringUnit_gross_register_ton = 4674132, /*  */
    EngineeringUnit_gross_ton = 18260, /*  */
    EngineeringUnit_gigajoule = 18262, /* GJ */
    EngineeringUnit_gigawatt_hour = 4675400, /* GW·h */
    EngineeringUnit_henry_per_kiloohm = 4730931, /* H/k? */
    EngineeringUnit_henry_per_ohm = 4730932, /* H/? */
    EngineeringUnit_millihenry_per_kiloohm = 4730933, /* mH/k? */
    EngineeringUnit_millihenry_per_ohm = 4730934, /* mH/? */
    EngineeringUnit_pascal_second_per_bar = 4730935, /* Pa·s/bar */
    EngineeringUnit_microbecquerel = 4730936, /* µBq */
    EngineeringUnit_reciprocal_year = 4730937, /* 1/y */
    EngineeringUnit_reciprocal_hour = 4731184, /* 1/h */
    EngineeringUnit_reciprocal_month = 4731185, /* 1/mo */
    EngineeringUnit_degree_Celsius_per_hour = 4731186, /* °C/h */
    EngineeringUnit_degree_Celsius_per_minute = 4731187, /* °C/min */
    EngineeringUnit_degree_Celsius_per_second = 4731188, /* °C/s */
    EngineeringUnit_square_centimetre_per_gram = 4731189, /* cm²/g */
    EngineeringUnit_square_decametre = 4731190, /* dam² */
    EngineeringUnit_square_hectometre = 4731192, /* hm² */
    EngineeringUnit_cubic_hectometre = 4731193, /* hm³ */
    EngineeringUnit_cubic_kilometre = 4731440, /* km³ */
    EngineeringUnit_blank = 4731441, /*  */
    EngineeringUnit_volt_square_inch_per_pound_force = 4731442, /* V/(lbf/in²) */
    EngineeringUnit_volt_per_inch = 4731443, /* V/in */
    EngineeringUnit_volt_per_microsecond = 4731444, /* V/µs */
    EngineeringUnit_percent_per_kelvin = 4731445, /* %/K */
    EngineeringUnit_ohm_per_metre = 4731446, /* ?/m */
    EngineeringUnit_degree_per_metre = 4731447, /* °/m */
    EngineeringUnit_microfarad_per_kilometre = 4731448, /* µF/km */
    EngineeringUnit_microgram_per_litre = 4731449, /* µg/l */
    EngineeringUnit_square_micrometre__square_micron_ = 4731696, /* µm² */
    EngineeringUnit_ampere_per_kilogram = 4731697, /* A/kg */
    EngineeringUnit_ampere_squared_second = 4731698, /* A²·s */
    EngineeringUnit_farad_per_kilometre = 4731699, /* F/km */
    EngineeringUnit_hertz_metre = 4731700, /* Hz·m */
    EngineeringUnit_kelvin_metre_per_watt = 4731701, /* K·m/W */
    EngineeringUnit_megaohm_per_kilometre = 4731702, /* M?/km */
    EngineeringUnit_megaohm_per_metre = 4731703, /* M?/m */
    EngineeringUnit_megaampere = 4731704, /* MA */
    EngineeringUnit_megahertz_kilometre = 4731705, /* MHz·km */
    EngineeringUnit_newton_per_ampere = 4731952, /* N/A */
    EngineeringUnit_newton_metre_watt_to_the_power_minus_0_5 = 4731953, /* N·m·W?°?5 */
    EngineeringUnit_pascal_per_metre = 4731954, /* Pa/m */
    EngineeringUnit_siemens_per_centimetre = 4731955, /* S/cm */
    EngineeringUnit_teraohm = 4731956, /* T? */
    EngineeringUnit_volt_second_per_metre = 4731957, /* V·s/m */
    EngineeringUnit_volt_per_second = 4731958, /* V/s */
    EngineeringUnit_watt_per_cubic_metre = 4731959, /* W/m³ */
    EngineeringUnit_attofarad = 4731960, /* aF */
    EngineeringUnit_centimetre_per_hour = 4731961, /* cm/h */
    EngineeringUnit_reciprocal_cubic_centimetre = 4732208, /* cm?³ */
    EngineeringUnit_decibel_per_kilometre = 4732209, /* dB/km */
    EngineeringUnit_decibel_per_metre = 4732210, /* dB/m */
    EngineeringUnit_kilogram_per_bar = 4732211, /* kg/bar */
    EngineeringUnit_kilogram_per_cubic_decimetre_kelvin = 4732212, /* (kg/dm³)/K */
    EngineeringUnit_kilogram_per_cubic_decimetre_bar = 4732213, /* (kg/dm³)/bar */
    EngineeringUnit_kilogram_per_square_metre_second = 4732214, /* kg/(m²·s) */
    EngineeringUnit_inch_per_two_pi_radiant = 4732215, /* in/revolution */
    EngineeringUnit_metre_per_volt_second = 4732216, /* m/(V·s) */
    EngineeringUnit_square_metre_per_newton = 4732217, /* m²/N */
    EngineeringUnit_cubic_metre_per_cubic_metre = 4732464, /* m³/m³ */
    EngineeringUnit_millisiemens_per_centimetre = 4732465, /* mS/cm */
    EngineeringUnit_millivolt_per_minute = 4732466, /* mV/min */
    EngineeringUnit_milligram_per_square_centimetre = 4732467, /* mg/cm² */
    EngineeringUnit_milligram_per_gram = 4732468, /* mg/g */
    EngineeringUnit_millilitre_per_cubic_metre = 4732469, /* ml/m³ */
    EngineeringUnit_millimetre_per_year = 4732470, /* mm/y */
    EngineeringUnit_millimetre_per_hour = 4732471, /* mm/h */
    EngineeringUnit_millimole_per_gram = 4732472, /* mmol/g */
    EngineeringUnit_picopascal_per_kilometre = 4732473, /* pPa/km */
    EngineeringUnit_picosecond = 4732720, /* ps */
    EngineeringUnit_percent_per_month = 4732721, /* %/mo */
    EngineeringUnit_percent_per_hectobar = 4732722, /* %/hbar */
    EngineeringUnit_percent_per_decakelvin = 4732723, /* %/daK */
    EngineeringUnit_watt_per_metre = 4732724, /* W/m */
    EngineeringUnit_decapascal = 4732725, /* daPa */
    EngineeringUnit_gram_per_millimetre = 4732726, /* g/mm */
    EngineeringUnit_module_width = 4732727, /* MW */
    EngineeringUnit_conventional_centimetre_of_water = 4732728, /* cm H2O */
    EngineeringUnit_French_gauge = 4732729, /* Fg */
    EngineeringUnit_rack_unit = 4732976, /* U or RU */
    EngineeringUnit_millimetre_per_minute = 4732977, /* mm/min */
    EngineeringUnit_big_point = 4732978, /* bp */
    EngineeringUnit_litre_per_kilogram = 4732979, /* l/kg */
    EngineeringUnit_gram_millimetre = 4732980, /* g·mm */
    EngineeringUnit_reciprocal_week = 4732981, /* 1/wk */
    EngineeringUnit_piece = 4732983, /*  */
    EngineeringUnit_megaohm_kilometre = 4732984, /* M?·km */
    EngineeringUnit_percent_per_ohm = 4732985, /* %/? */
    EngineeringUnit_percent_per_degree = 4733232, /* %/° */
    EngineeringUnit_percent_per_ten_thousand = 4733233, /* %/10000 */
    EngineeringUnit_percent_per_one_hundred_thousand = 4733234, /* %/100000 */
    EngineeringUnit_percent_per_hundred = 4733235, /* %/100 */
    EngineeringUnit_percent_per_thousand = 4733236, /* %/1000 */
    EngineeringUnit_percent_per_volt = 4733237, /* %/V */
    EngineeringUnit_percent_per_bar = 4733238, /* %/bar */
    EngineeringUnit_percent_per_inch = 4733240, /* %/in */
    EngineeringUnit_percent_per_metre = 4733241, /* %/m */
    EngineeringUnit_hank = 18497, /*  */
    EngineeringUnit_hectare = 4735314, /* ha */
    EngineeringUnit_hectobar = 4735553, /* hbar */
    EngineeringUnit_hundred_boxes = 4735576, /*  */
    EngineeringUnit_hundred_count = 18499, /*  */
    EngineeringUnit_hundred_kilogram__dry_weight = 4736087, /*  */
    EngineeringUnit_head = 4736321, /*  */
    EngineeringUnit_hectogram = 4736845, /* hg */
    EngineeringUnit_hundred_cubic_foot = 18504, /*  */
    EngineeringUnit_hundred_international_unit = 4737365, /*  */
    EngineeringUnit_metric_horse_power = 18506, /* metric hp */
    EngineeringUnit_hundred_kilogram__net_mass = 4737869, /*  */
    EngineeringUnit_hectolitre = 4738132, /* hl */
    EngineeringUnit_mile_per_hour__statute_mile_ = 18509, /* mile/h */
    EngineeringUnit_million_cubic_metre = 4738385, /* Mm³ */
    EngineeringUnit_hectometre = 4738388, /* hm */
    EngineeringUnit_conventional_millimetre_of_mercury = 18510, /* mm Hg */
    EngineeringUnit_conventional_millimetre_of_water = 18512, /* mm H2O */
    EngineeringUnit_hectolitre_of_pure_alcohol = 4739137, /*  */
    EngineeringUnit_hertz = 4740186, /* Hz */
    EngineeringUnit_hour = 4740434, /* h */
    EngineeringUnit_inch_pound__pound_inch_ = 18753, /* in·lb */
    EngineeringUnit_person = 18757, /*  */
    EngineeringUnit_inch = 4804168, /* in */
    EngineeringUnit_square_inch = 4804171, /* in² */
    EngineeringUnit_cubic_inch = 4804177, /* in³ */
    EngineeringUnit_international_sugar_degree = 4805444, /*  */
    EngineeringUnit_inch_per_second = 18773, /* in/s */
    EngineeringUnit_inch_per_second_squared = 18774, /* in/s² */
    EngineeringUnit_percent_per_millimetre = 4862256, /* %/mm */
    EngineeringUnit_per_mille_per_psi = 4862258, /* ‰/psi */
    EngineeringUnit_degree_API = 4862259, /* °API */
    EngineeringUnit_degree_Baume__origin_scale_ = 4862260, /* °Bé */
    EngineeringUnit_degree_Baume__US_heavy_ = 4862261, /* °Bé (US heavy) */
    EngineeringUnit_degree_Baume__US_light_ = 4862262, /* °Bé (US light) */
    EngineeringUnit_degree_Balling = 4862263, /* °Balling */
    EngineeringUnit_degree_Brix = 4862264, /* °Bx */
    EngineeringUnit_degree_Fahrenheit_hour_square_foot_per_British_thermal_unit__thermochemical_ = 4862265, /* °F·h·ft²/Btuth */
    EngineeringUnit_joule_per_kilogram = 18994, /* J/kg */
    EngineeringUnit_degree_Fahrenheit_per_kelvin = 4862512, /* °F/K */
    EngineeringUnit_degree_Fahrenheit_per_bar = 4862513, /* °F/bar */
    EngineeringUnit_degree_Fahrenheit_hour_square_foot_per_British_thermal_unit__international_table_ = 4862514, /* °F·h·ft²/BtuIT */
    EngineeringUnit_degree_Fahrenheit_per_hour = 4862515, /* °F/h */
    EngineeringUnit_degree_Fahrenheit_per_minute = 4862516, /* °F/min */
    EngineeringUnit_degree_Fahrenheit_per_second = 4862517, /* °F/s */
    EngineeringUnit_reciprocal_degree_Fahrenheit = 4862518, /* 1/°F */
    EngineeringUnit_degree_Oechsle = 4862519, /* °Oechsle */
    EngineeringUnit_degree_Rankine_per_hour = 4862520, /* °R/h */
    EngineeringUnit_degree_Rankine_per_minute = 4862521, /* °R/min */
    EngineeringUnit_degree_Rankine_per_second = 4862768, /* °R/s */
    EngineeringUnit_degree_Twaddell = 4862769, /* °Tw */
    EngineeringUnit_micropoise = 4862770, /* µP */
    EngineeringUnit_microgram_per_kilogram = 4862771, /* µg/kg */
    EngineeringUnit_microgram_per_cubic_metre_kelvin = 4862772, /* (µg/m³)/K */
    EngineeringUnit_microgram_per_cubic_metre_bar = 4862773, /* (µg/m³)/bar */
    EngineeringUnit_microlitre_per_litre = 4862774, /* µl/l */
    EngineeringUnit_baud = 4862776, /* Bd */
    EngineeringUnit_British_thermal_unit__mean_ = 4862777, /* Btu */
    EngineeringUnit_British_thermal_unit__international_table__foot_per_hour_square_foot_degree_Fahrenheit = 4863024, /* BtuIT·ft/(h·ft²·°F) */
    EngineeringUnit_British_thermal_unit__international_table__inch_per_hour_square_foot_degree_Fahrenheit = 4863025, /* BtuIT·in/(h·ft²·°F) */
    EngineeringUnit_British_thermal_unit__international_table__inch_per_second_square_foot_degree_Fahrenheit = 4863026, /* BtuIT·in/(s·ft²·°F) */
    EngineeringUnit_British_thermal_unit__international_table__per_pound_degree_Fahrenheit = 4863027, /* BtuIT/(lb·°F) */
    EngineeringUnit_British_thermal_unit__international_table__per_minute = 4863028, /* BtuIT/min */
    EngineeringUnit_British_thermal_unit__international_table__per_second = 4863029, /* BtuIT/s */
    EngineeringUnit_British_thermal_unit__thermochemical__foot_per_hour_square_foot_degree_Fahrenheit = 4863030, /* Btuth·ft/(h·ft²·°F) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_hour = 4863031, /* Btuth/h */
    EngineeringUnit_British_thermal_unit__thermochemical__inch_per_hour_square_foot_degree_Fahrenheit = 4863032, /* Btuth·in/(h·ft²·°F) */
    EngineeringUnit_British_thermal_unit__thermochemical__inch_per_second_square_foot_degree_Fahrenheit = 4863033, /* Btuth·in/(s·ft²·°F) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_pound_degree_Fahrenheit = 4863280, /* Btuth/(lb·°F) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_minute = 4863281, /* Btuth/min */
    EngineeringUnit_British_thermal_unit__thermochemical__per_second = 4863282, /* Btuth/s */
    EngineeringUnit_coulomb_square_metre_per_kilogram = 4863283, /* C·m²/kg */
    EngineeringUnit_megabaud = 4863284, /* MBd */
    EngineeringUnit_watt_second = 4863285, /* W·s */
    EngineeringUnit_bar_per_bar = 4863286, /* bar/bar */
    EngineeringUnit_barrel__UK_petroleum_ = 4863287, /* bbl (UK liq.) */
    EngineeringUnit_barrel__UK_petroleum__per_minute = 4863288, /* bbl (UK liq.)/min */
    EngineeringUnit_barrel__UK_petroleum__per_day = 4863289, /* bbl (UK liq.)/d */
    EngineeringUnit_barrel__UK_petroleum__per_hour = 4863536, /* bbl (UK liq.)/h */
    EngineeringUnit_barrel__UK_petroleum__per_second = 4863537, /* bbl (UK liq.)/s */
    EngineeringUnit_barrel__US_petroleum__per_hour = 4863538, /* bbl (US)/h */
    EngineeringUnit_barrel__US_petroleum__per_second = 4863539, /* bbl (US)/s */
    EngineeringUnit_bushel__UK__per_day = 4863540, /* bu (UK)/d */
    EngineeringUnit_bushel__UK__per_hour = 4863541, /* bu (UK)/h */
    EngineeringUnit_bushel__UK__per_minute = 4863542, /* bu (UK)/min */
    EngineeringUnit_bushel__UK__per_second = 4863543, /* bu (UK)/s */
    EngineeringUnit_bushel__US_dry__per_day = 4863544, /* bu (US dry)/d */
    EngineeringUnit_bushel__US_dry__per_hour = 4863545, /* bu (US dry)/h */
    EngineeringUnit_bushel__US_dry__per_minute = 4863792, /* bu (US dry)/min */
    EngineeringUnit_bushel__US_dry__per_second = 4863793, /* bu (US dry)/s */
    EngineeringUnit_centinewton_metre = 4863794, /* cN·m */
    EngineeringUnit_centipoise_per_kelvin = 4863795, /* cP/K */
    EngineeringUnit_centipoise_per_bar = 4863796, /* cP/bar */
    EngineeringUnit_calorie__mean_ = 4863797, /* cal */
    EngineeringUnit_calorie__international_table__per_gram_degree_Celsius = 4863798, /* calIT/(g·°C) */
    EngineeringUnit_calorie__thermochemical__per_centimetre_second_degree_Celsius = 4863800, /* calth/(cm·s·°C) */
    EngineeringUnit_calorie__thermochemical__per_gram_degree_Celsius = 4863801, /* calth/(g·°C) */
    EngineeringUnit_calorie__thermochemical__per_minute = 4864049, /* calth/min */
    EngineeringUnit_calorie__thermochemical__per_second = 4864050, /* calth/s */
    EngineeringUnit_clo = 4864051, /* clo */
    EngineeringUnit_centimetre_per_second_kelvin = 4864052, /* (cm/s)/K */
    EngineeringUnit_centimetre_per_second_bar = 4864053, /* (cm/s)/bar */
    EngineeringUnit_cubic_centimetre_per_cubic_metre = 4864055, /* cm³/m³ */
    EngineeringUnit_centimetre_of_mercury = 4864057, /* cm Hg */
    EngineeringUnit_cubic_decimetre_per_day = 4864304, /* dm³/d */
    EngineeringUnit_cubic_decimetre_per_cubic_metre = 4864305, /* dm³/m³ */
    EngineeringUnit_cubic_decimetre_per_minute = 4864306, /* dm³/min */
    EngineeringUnit_cubic_decimetre_per_second = 4864307, /* dm³/s */
    EngineeringUnit_dyne_centimetre = 4864308, /* dyn·cm */
    EngineeringUnit_ounce__UK_fluid__per_day = 4864309, /* fl oz (UK)/d */
    EngineeringUnit_ounce__UK_fluid__per_hour = 4864310, /* fl oz (UK)/h */
    EngineeringUnit_ounce__UK_fluid__per_minute = 4864311, /* fl oz (UK)/min */
    EngineeringUnit_ounce__UK_fluid__per_second = 4864312, /* fl oz (UK)/s */
    EngineeringUnit_ounce__US_fluid__per_day = 4864313, /* fl oz (US)/d */
    EngineeringUnit_joule_per_kelvin = 19013, /* J/K */
    EngineeringUnit_megajoule_per_kilogram = 19019, /* MJ/kg */
    EngineeringUnit_megajoule_per_cubic_metre = 19021, /* MJ/m³ */
    EngineeringUnit_pipeline_joint = 4869716, /*  */
    EngineeringUnit_joule = 4869973, /* J */
    EngineeringUnit_hundred_metre = 4870227, /*  */
    EngineeringUnit_number_of_jewels = 4872012, /*  */
    EngineeringUnit_kilowatt_demand = 19249, /*  */
    EngineeringUnit_ounce__US_fluid__per_hour = 4927792, /* fl oz (US)/h */
    EngineeringUnit_ounce__US_fluid__per_minute = 4927793, /* fl oz (US)/min */
    EngineeringUnit_ounce__US_fluid__per_second = 4927794, /* fl oz (US)/s */
    EngineeringUnit_foot_per_degree_Fahrenheit = 4927795, /* ft/°F */
    EngineeringUnit_foot_per_hour = 4927796, /* ft/h */
    EngineeringUnit_foot_pound_force_per_hour = 4927797, /* ft·lbf/h */
    EngineeringUnit_foot_pound_force_per_minute = 4927798, /* ft·lbf/min */
    EngineeringUnit_foot_per_psi = 4927799, /* ft/psi */
    EngineeringUnit_foot_per_second_degree_Fahrenheit = 4927800, /* (ft/s)/°F */
    EngineeringUnit_foot_per_second_psi = 4927801, /* (ft/s)/psi */
    EngineeringUnit_kilovolt_ampere_reactive_demand = 19250, /*  */
    EngineeringUnit_reciprocal_cubic_foot = 4928048, /* 1/ft³ */
    EngineeringUnit_cubic_foot_per_degree_Fahrenheit = 4928049, /* ft³/°F */
    EngineeringUnit_cubic_foot_per_day = 4928050, /* ft³/d */
    EngineeringUnit_cubic_foot_per_psi = 4928051, /* ft³/psi */
    EngineeringUnit_foot_of_water = 4928052, /* ft H2O */
    EngineeringUnit_foot_of_mercury = 4928053, /* ft Hg */
    EngineeringUnit_gallon__UK__per_day = 4928054, /* gal (UK)/d */
    EngineeringUnit_gallon__UK__per_hour = 4928055, /* gal (UK)/h */
    EngineeringUnit_gallon__UK__per_second = 4928056, /* gal (UK)/s */
    EngineeringUnit_kilovolt_ampere_reactive_hour = 19251, /* kvar·h */
    EngineeringUnit_gallon__US_liquid__per_second = 4928304, /* gal (US liq.)/s */
    EngineeringUnit_gram_force_per_square_centimetre = 4928305, /* gf/cm² */
    EngineeringUnit_gill__UK__per_day = 4928306, /* gi (UK)/d */
    EngineeringUnit_gill__UK__per_hour = 4928307, /* gi (UK)/h */
    EngineeringUnit_gill__UK__per_minute = 4928308, /* gi (UK)/min */
    EngineeringUnit_gill__UK__per_second = 4928309, /* gi (UK)/s */
    EngineeringUnit_gill__US__per_day = 4928310, /* gi (US)/d */
    EngineeringUnit_gill__US__per_hour = 4928311, /* gi (US)/h */
    EngineeringUnit_gill__US__per_minute = 4928312, /* gi (US)/min */
    EngineeringUnit_gill__US__per_second = 4928313, /* gi (US)/s */
    EngineeringUnit_standard_acceleration_of_free_fall = 4928560, /* gn */
    EngineeringUnit_grain_per_gallon__US_ = 4928561, /* gr/gal (US) */
    EngineeringUnit_horsepower__boiler_ = 4928562, /* boiler hp */
    EngineeringUnit_horsepower__electric_ = 4928563, /* electric hp */
    EngineeringUnit_inch_per_degree_Fahrenheit = 4928565, /* in/°F */
    EngineeringUnit_inch_per_psi = 4928566, /* in/psi */
    EngineeringUnit_inch_per_second_degree_Fahrenheit = 4928567, /* (in/s)/°F */
    EngineeringUnit_inch_per_second_psi = 4928568, /* (in/s)/psi */
    EngineeringUnit_reciprocal_cubic_inch = 4928569, /* 1/in³ */
    EngineeringUnit_kilovolt_ampere__reactive_ = 19253, /* kvar */
    EngineeringUnit_kilobaud = 4928816, /* kBd */
    EngineeringUnit_kilocalorie__mean_ = 4928817, /* kcal */
    EngineeringUnit_kilocalorie__international_table__per_hour_metre_degree_Celsius = 4928818, /* kcal/(m·h·°C) */
    EngineeringUnit_kilocalorie__thermochemical_ = 4928819, /* kcalth */
    EngineeringUnit_kilocalorie__thermochemical__per_minute = 4928820, /* kcalth/min */
    EngineeringUnit_kilocalorie__thermochemical__per_second = 4928821, /* kcalth/s */
    EngineeringUnit_kilomole_per_hour = 4928824, /* kmol/h */
    EngineeringUnit_kilomole_per_cubic_metre_kelvin = 4928825, /* (kmol/m³)/K */
    EngineeringUnit_kilolitre = 19254, /* kl */
    EngineeringUnit_kilomole_per_cubic_metre_bar = 4929072, /* (kmol/m³)/bar */
    EngineeringUnit_kilomole_per_minute = 4929073, /* kmol/min */
    EngineeringUnit_litre_per_litre = 4929074, /* l/l */
    EngineeringUnit_reciprocal_litre = 4929075, /* 1/l */
    EngineeringUnit_pound__avoirdupois__per_degree_Fahrenheit = 4929076, /* lb/°F */
    EngineeringUnit_pound__avoirdupois__square_foot = 4929077, /* lb·ft² */
    EngineeringUnit_pound__avoirdupois__per_day = 4929078, /* lb/d */
    EngineeringUnit_pound_per_foot_hour = 4929079, /* lb/(ft·h) */
    EngineeringUnit_pound_per_foot_second = 4929080, /* lb/(ft·s) */
    EngineeringUnit_pound__avoirdupois__per_cubic_foot_degree_Fahrenheit = 4929081, /* (lb/ft³)/°F */
    EngineeringUnit_pound__avoirdupois__per_cubic_foot_psi = 4929328, /* (lb/ft³)/psi */
    EngineeringUnit_pound__avoirdupois__per_gallon__UK_ = 4929329, /* lb/gal (UK) */
    EngineeringUnit_pound__avoirdupois__per_hour_degree_Fahrenheit = 4929331, /* (lb/h)/°F */
    EngineeringUnit_pound__avoirdupois__per_hour_psi = 4929332, /* (lb/h)/psi */
    EngineeringUnit_pound__avoirdupois__per_cubic_inch_degree_Fahrenheit = 4929333, /* (lb/in³)/°F */
    EngineeringUnit_pound__avoirdupois__per_cubic_inch_psi = 4929334, /* (lb/in³)/psi */
    EngineeringUnit_pound__avoirdupois__per_psi = 4929335, /* lb/psi */
    EngineeringUnit_pound__avoirdupois__per_minute = 4929336, /* lb/min */
    EngineeringUnit_pound__avoirdupois__per_minute_degree_Fahrenheit = 4929337, /* lb/(min·°F) */
    EngineeringUnit_pound__avoirdupois__per_minute_psi = 4929584, /* (lb/min)/psi */
    EngineeringUnit_pound__avoirdupois__per_second = 4929585, /* lb/s */
    EngineeringUnit_pound__avoirdupois__per_second_degree_Fahrenheit = 4929586, /* (lb/s)/°F */
    EngineeringUnit_pound__avoirdupois__per_second_psi = 4929587, /* (lb/s)/psi */
    EngineeringUnit_pound_per_cubic_yard = 4929588, /* lb/yd³ */
    EngineeringUnit_pound_force_per_square_foot = 4929589, /* lbf/ft² */
    EngineeringUnit_pound_force_per_square_inch_degree_Fahrenheit = 4929590, /* psi/°F */
    EngineeringUnit_psi_cubic_inch_per_second = 4929591, /* psi·in³/s */
    EngineeringUnit_psi_litre_per_second = 4929592, /* psi·l/s */
    EngineeringUnit_psi_cubic_metre_per_second = 4929593, /* psi·m³/s */
    EngineeringUnit_psi_cubic_yard_per_second = 4929840, /* psi·yd³/s */
    EngineeringUnit_pound_force_second_per_square_foot = 4929841, /* lbf·s/ft² */
    EngineeringUnit_pound_force_second_per_square_inch = 4929842, /* lbf·s/in² */
    EngineeringUnit_reciprocal_psi = 4929843, /* 1/psi */
    EngineeringUnit_quart__UK_liquid__per_day = 4929844, /* qt (UK liq.)/d */
    EngineeringUnit_quart__UK_liquid__per_hour = 4929845, /* qt (UK liq.)/h */
    EngineeringUnit_quart__UK_liquid__per_minute = 4929846, /* qt (UK liq.)/min */
    EngineeringUnit_quart__UK_liquid__per_second = 4929847, /* qt (UK liq.)/s */
    EngineeringUnit_quart__US_liquid__per_day = 4929848, /* qt (US liq.)/d */
    EngineeringUnit_quart__US_liquid__per_hour = 4929849, /* qt (US liq.)/h */
    EngineeringUnit_cake = 19265, /*  */
    EngineeringUnit_katal = 4931924, /* kat */
    EngineeringUnit_kilocharacter = 19266, /*  */
    EngineeringUnit_kilobar = 4932161, /* kbar */
    EngineeringUnit_kilogram_of_choline_chloride = 4932419, /* kg C5 H14ClNO */
    EngineeringUnit_kilogram_drained_net_weight = 4932695, /* kg/net eda */
    EngineeringUnit_kelvin = 4932940, /* K */
    EngineeringUnit_kilogram = 4933453, /* kg */
    EngineeringUnit_kilogram_per_second = 4933459, /* kg/s */
    EngineeringUnit_kilogram_of_hydrogen_peroxide = 4933721, /* kg H2O2 */
    EngineeringUnit_kilohertz = 4933722, /* kHz */
    EngineeringUnit_kilogram_per_millimetre_width = 19273, /*  */
    EngineeringUnit_kilogram__including_container = 4933955, /*  */
    EngineeringUnit_kilogram__including_inner_packaging = 4933968, /*  */
    EngineeringUnit_kilosegment = 19274, /*  */
    EngineeringUnit_kilojoule = 4934223, /* kJ */
    EngineeringUnit_kilogram_per_metre = 19276, /* kg/m */
    EngineeringUnit_lactic_dry_material_percentage = 4934731, /*  */
    EngineeringUnit_kilolux = 4934744, /* klx */
    EngineeringUnit_kilogram_of_methylamine = 4934977, /* kg met.am. */
    EngineeringUnit_kilometre_per_hour = 4934984, /* km/h */
    EngineeringUnit_square_kilometre = 4934987, /* km² */
    EngineeringUnit_kilogram_per_cubic_metre = 4934993, /* kg/m³ */
    EngineeringUnit_kilometre = 4934996, /* km */
    EngineeringUnit_kilogram_of_nitrogen = 4935241, /* kg N */
    EngineeringUnit_kilogram_named_substance = 4935251, /*  */
    EngineeringUnit_knot = 4935252, /* kn */
    EngineeringUnit_milliequivalence_caustic_potash_per_gram_of_product = 19279, /*  */
    EngineeringUnit_kilopascal = 4935745, /* kPa */
    EngineeringUnit_kilogram_of_potassium_hydroxide__caustic_potash_ = 4935752, /* kg KOH */
    EngineeringUnit_kilogram_of_potassium_oxide = 4935759, /* kg K2O */
    EngineeringUnit_kilogram_of_phosphorus_pentoxide__phosphoric_anhydride_ = 4935760, /*  */
    EngineeringUnit_kiloroentgen = 19282, /* kR */
    EngineeringUnit_kilogram_of_substance_90___dry = 4936516, /* kg 90 % sdt */
    EngineeringUnit_kilogram_of_sodium_hydroxide__caustic_soda_ = 4936520, /* kg NaOH */
    EngineeringUnit_kit = 19284, /*  */
    EngineeringUnit_kilotonne = 4936782, /* kt */
    EngineeringUnit_kilogram_of_uranium = 4937042, /* kg U */
    EngineeringUnit_kilovolt___ampere = 4937281, /* kV·A */
    EngineeringUnit_kilovar = 4937298, /* kvar */
    EngineeringUnit_kilovolt = 4937300, /* kV */
    EngineeringUnit_kilogram_per_millimetre = 19287, /* kg/mm */
    EngineeringUnit_kilowatt_hour = 4937544, /* kW·h */
    EngineeringUnit_kilogram_of_tungsten_trioxide = 4937551, /* kg WO3 */
    EngineeringUnit_kilowatt = 4937556, /* kW */
    EngineeringUnit_millilitre_per_kilogram = 19288, /* ml/kg */
    EngineeringUnit_quart__US_liquid__per_minute = 4993328, /* qt (US liq.)/min */
    EngineeringUnit_quart__US_liquid__per_second = 4993329, /* qt (US liq.)/s */
    EngineeringUnit_metre_per_second_kelvin = 4993330, /* (m/s)/K */
    EngineeringUnit_metre_per_second_bar = 4993331, /* (m/s)/bar */
    EngineeringUnit_square_metre_hour_degree_Celsius_per_kilocalorie__international_table_ = 4993332, /* m²·h·°C/kcal */
    EngineeringUnit_millipascal_second_per_kelvin = 4993333, /* mPa·s/K */
    EngineeringUnit_millipascal_second_per_bar = 4993334, /* mPa·s/bar */
    EngineeringUnit_milligram_per_cubic_metre_kelvin = 4993335, /* (mg/m³)/K */
    EngineeringUnit_milligram_per_cubic_metre_bar = 4993336, /* (mg/m³)/bar */
    EngineeringUnit_millilitre_per_litre = 4993337, /* ml/l */
    EngineeringUnit_litre_per_minute = 19506, /* l/min */
    EngineeringUnit_reciprocal_cubic_millimetre = 4993584, /* 1/mm³ */
    EngineeringUnit_cubic_millimetre_per_cubic_metre = 4993585, /* mm³/m³ */
    EngineeringUnit_mole_per_hour = 4993587, /* mol/h */
    EngineeringUnit_mole_per_kilogram_kelvin = 4993588, /* (mol/kg)/K */
    EngineeringUnit_mole_per_kilogram_bar = 4993589, /* (mol/kg)/bar */
    EngineeringUnit_mole_per_litre_kelvin = 4993590, /* (mol/l)/K */
    EngineeringUnit_mole_per_litre_bar = 4993591, /* (mol/l)/bar */
    EngineeringUnit_mole_per_cubic_metre_kelvin = 4993592, /* (mol/m³)/K */
    EngineeringUnit_mole_per_cubic_metre_bar = 4993593, /* (mol/m³)/bar */
    EngineeringUnit_mole_per_minute = 4993840, /* mol/min */
    EngineeringUnit_milliroentgen_aequivalent_men = 4993841, /* mrem */
    EngineeringUnit_nanogram_per_kilogram = 4993842, /* ng/kg */
    EngineeringUnit_ounce__avoirdupois__per_day = 4993843, /* oz/d */
    EngineeringUnit_ounce__avoirdupois__per_hour = 4993844, /* oz/h */
    EngineeringUnit_ounce__avoirdupois__per_minute = 4993845, /* oz/min */
    EngineeringUnit_ounce__avoirdupois__per_second = 4993846, /* oz/s */
    EngineeringUnit_ounce__avoirdupois__per_gallon__UK_ = 4993847, /* oz/gal (UK) */
    EngineeringUnit_ounce__avoirdupois__per_gallon__US_ = 4993848, /* oz/gal (US) */
    EngineeringUnit_ounce__avoirdupois__per_cubic_inch = 4993849, /* oz/in³ */
    EngineeringUnit_ounce__avoirdupois__force = 4994096, /* ozf */
    EngineeringUnit_ounce__avoirdupois__force_inch = 4994097, /* ozf·in */
    EngineeringUnit_picosiemens_per_metre = 4994098, /* pS/m */
    EngineeringUnit_peck__UK_ = 4994099, /* pk (UK) */
    EngineeringUnit_peck__UK__per_day = 4994100, /* pk (UK)/d */
    EngineeringUnit_peck__UK__per_hour = 4994101, /* pk (UK)/h */
    EngineeringUnit_peck__UK__per_minute = 4994102, /* pk (UK)/min */
    EngineeringUnit_peck__UK__per_second = 4994103, /* pk (UK)/s */
    EngineeringUnit_peck__US_dry__per_day = 4994104, /* pk (US dry)/d */
    EngineeringUnit_peck__US_dry__per_hour = 4994105, /* pk (US dry)/h */
    EngineeringUnit_peck__US_dry__per_minute = 4994352, /* pk (US dry)/min */
    EngineeringUnit_peck__US_dry__per_second = 4994353, /* pk (US dry)/s */
    EngineeringUnit_psi_per_psi = 4994354, /* psi/psi */
    EngineeringUnit_pint__UK__per_day = 4994355, /* pt (UK)/d */
    EngineeringUnit_pint__UK__per_hour = 4994356, /* pt (UK)/h */
    EngineeringUnit_pint__UK__per_minute = 4994357, /* pt (UK)/min */
    EngineeringUnit_pint__UK__per_second = 4994358, /* pt (UK)/s */
    EngineeringUnit_pint__US_liquid__per_day = 4994359, /* pt (US liq.)/d */
    EngineeringUnit_pint__US_liquid__per_hour = 4994360, /* pt (US liq.)/h */
    EngineeringUnit_pint__US_liquid__per_minute = 4994361, /* pt (US liq.)/min */
    EngineeringUnit_pint__US_liquid__per_second = 4994608, /* pt (US liq.)/s */
    EngineeringUnit_slug_per_day = 4994611, /* slug/d */
    EngineeringUnit_slug_per_foot_second = 4994612, /* slug/(ft·s) */
    EngineeringUnit_slug_per_cubic_foot = 4994613, /* slug/ft³ */
    EngineeringUnit_slug_per_hour = 4994614, /* slug/h */
    EngineeringUnit_slug_per_minute = 4994615, /* slug/min */
    EngineeringUnit_slug_per_second = 4994616, /* slug/s */
    EngineeringUnit_tonne_per_kelvin = 4994617, /* t/K */
    EngineeringUnit_tonne_per_bar = 4994864, /* t/bar */
    EngineeringUnit_tonne_per_day = 4994865, /* t/d */
    EngineeringUnit_tonne_per_day_kelvin = 4994866, /* (t/d)/K */
    EngineeringUnit_tonne_per_day_bar = 4994867, /* (t/d)/bar */
    EngineeringUnit_tonne_per_hour_kelvin = 4994868, /* (t/h)/K */
    EngineeringUnit_tonne_per_hour_bar = 4994869, /* (t/h)/bar */
    EngineeringUnit_tonne_per_cubic_metre_kelvin = 4994870, /* (t/m³)/K */
    EngineeringUnit_tonne_per_cubic_metre_bar = 4994871, /* (t/m³)/bar */
    EngineeringUnit_tonne_per_minute = 4994872, /* t/min */
    EngineeringUnit_tonne_per_minute_kelvin = 4994873, /* (t/min)/K */
    EngineeringUnit_tonne_per_minute_bar = 4995120, /* (t/min)/bar */
    EngineeringUnit_tonne_per_second = 4995121, /* t/s */
    EngineeringUnit_tonne_per_second_kelvin = 4995122, /* (t/s)/K */
    EngineeringUnit_tonne_per_second_bar = 4995123, /* (t/s)/bar */
    EngineeringUnit_ton__UK_shipping_ = 4995124, /* British shipping ton */
    EngineeringUnit_ton_long_per_day = 4995125, /* ton (UK)/d */
    EngineeringUnit_ton__US_shipping_ = 4995126, /* (US) shipping ton */
    EngineeringUnit_ton_short_per_degree_Fahrenheit = 4995127, /* ton (US)/°F */
    EngineeringUnit_ton_short_per_day = 4995128, /* ton (US)/d */
    EngineeringUnit_ton_short_per_hour_degree_Fahrenheit = 4995129, /* ton (US)/(h·°F) */
    EngineeringUnit_ton_short_per_hour_psi = 4995376, /* (ton (US)/h)/psi */
    EngineeringUnit_ton_short_per_psi = 4995377, /* ton (US)/psi */
    EngineeringUnit_ton__UK_long__per_cubic_yard = 4995378, /* ton.l/yd³ (UK) */
    EngineeringUnit_ton__US_short__per_cubic_yard = 4995379, /* ton.s/yd³ (US) */
    EngineeringUnit_ton_force__US_short_ = 4995380, /* ton.sh-force */
    EngineeringUnit_common_year = 4995381, /* y (365 days) */
    EngineeringUnit_sidereal_year = 4995382, /* y (sidereal) */
    EngineeringUnit_yard_per_degree_Fahrenheit = 4995384, /* yd/°F */
    EngineeringUnit_yard_per_psi = 4995385, /* yd/psi */
    EngineeringUnit_pound_per_cubic_inch = 19521, /* lb/in³ */
    EngineeringUnit_lactose_excess_percentage = 4997443, /*  */
    EngineeringUnit_pound = 4997714, /* lb */
    EngineeringUnit_troy_pound__US_ = 4997716, /*  */
    EngineeringUnit_litre_per_day = 19524, /* l/d */
    EngineeringUnit_leaf = 4998470, /*  */
    EngineeringUnit_linear_foot = 19526, /*  */
    EngineeringUnit_labour_hour = 19528, /*  */
    EngineeringUnit_link = 19531, /*  */
    EngineeringUnit_linear_metre = 19533, /*  */
    EngineeringUnit_length = 19534, /*  */
    EngineeringUnit_lot___unit_of_procurement_ = 19535, /*  */
    EngineeringUnit_liquid_pound = 19536, /*  */
    EngineeringUnit_litre_of_pure_alcohol = 5001281, /*  */
    EngineeringUnit_layer = 19538, /*  */
    EngineeringUnit_lump_sum = 19539, /*  */
    EngineeringUnit_ton__UK__or_long_ton__US_ = 5002318, /* ton (UK) */
    EngineeringUnit_litre = 5002322, /* l */
    EngineeringUnit_metric_ton__lubricating_oil = 5002562, /*  */
    EngineeringUnit_lumen = 5002573, /* lm */
    EngineeringUnit_lux = 5002584, /* lx */
    EngineeringUnit_linear_yard = 19545, /*  */
    EngineeringUnit_milligram_per_litre = 19761, /* mg/l */
    EngineeringUnit_reciprocal_cubic_yard = 5058864, /* 1/yd³ */
    EngineeringUnit_cubic_yard_per_degree_Fahrenheit = 5058865, /* yd³/°F */
    EngineeringUnit_cubic_yard_per_day = 5058866, /* yd³/d */
    EngineeringUnit_cubic_yard_per_hour = 5058867, /* yd³/h */
    EngineeringUnit_cubic_yard_per_psi = 5058868, /* yd³/psi */
    EngineeringUnit_cubic_yard_per_minute = 5058869, /* yd³/min */
    EngineeringUnit_cubic_yard_per_second = 5058870, /* yd³/s */
    EngineeringUnit_kilohertz_metre = 5058871, /* kHz·m */
    EngineeringUnit_gigahertz_metre = 5058872, /* GHz·m */
    EngineeringUnit_Beaufort = 5058873, /* Bft */
    EngineeringUnit_reciprocal_megakelvin_or_megakelvin_to_the_power_minus_one = 5059120, /* 1/MK */
    EngineeringUnit_reciprocal_kilovolt___ampere_reciprocal_hour = 5059121, /* 1/kVAh */
    EngineeringUnit_millilitre_per_square_centimetre_minute = 5059122, /* (ml/min)/cm² */
    EngineeringUnit_newton_per_centimetre = 5059123, /* N/cm */
    EngineeringUnit_ohm_kilometre = 5059124, /* ?·km */
    EngineeringUnit_percent_per_degree_Celsius = 5059125, /* %/°C */
    EngineeringUnit_gigaohm_per_metre = 5059126, /* G?/m */
    EngineeringUnit_megahertz_metre = 5059127, /* MHz·m */
    EngineeringUnit_kilogram_per_kilogram = 5059129, /* kg/kg */
    EngineeringUnit_reciprocal_volt___ampere_reciprocal_second = 5059376, /* 1/(V·A·s) */
    EngineeringUnit_kilogram_per_kilometre = 5059377, /* kg/km */
    EngineeringUnit_pascal_second_per_litre = 5059378, /* Pa·s/l */
    EngineeringUnit_millimole_per_litre = 5059379, /* mmol/l */
    EngineeringUnit_newton_metre_per_square_metre = 5059380, /* N·m/m² */
    EngineeringUnit_millivolt___ampere = 5059381, /* mV·A */
    EngineeringUnit_S30_day_month = 5059382, /* mo (30 days) */
    EngineeringUnit_actual_360 = 5059383, /* y (360 days) */
    EngineeringUnit_kilometre_per_second_squared = 5059384, /* km/s² */
    EngineeringUnit_centimetre_per_second_squared = 5059385, /* cm/s² */
    EngineeringUnit_monetary_value = 19764, /*  */
    EngineeringUnit_yard_per_second_squared = 5059632, /* yd/s² */
    EngineeringUnit_millimetre_per_second_squared = 5059633, /* mm/s² */
    EngineeringUnit_mile__statute_mile__per_second_squared = 5059634, /* mi/s² */
    EngineeringUnit_mil = 5059635, /* mil */
    EngineeringUnit_revolution = 5059636, /* rev */
    EngineeringUnit_degree__unit_of_angle__per_second_squared = 5059637, /* °/s² */
    EngineeringUnit_revolution_per_minute_ = 5059638, /* r/min */
    EngineeringUnit_circular_mil_ = 5059639, /* cmil */
    EngineeringUnit_square_mile__based_on_U_S__survey_foot__ = 5059640, /* mi² (US survey) */
    EngineeringUnit_chain__based_on_U_S__survey_foot_ = 5059641, /* ch (US survey)  */
    EngineeringUnit_microcurie = 19765, /* µCi */
    EngineeringUnit_furlong = 5059888, /* fur */
    EngineeringUnit_foot__U_S__survey__ = 5059889, /* ft (US survey)  */
    EngineeringUnit_mile__based_on_U_S__survey_foot__ = 5059890, /* mi (US survey)  */
    EngineeringUnit_metre_per_pascal = 5059891, /* m/Pa */
    EngineeringUnit_metre_per_radiant = 5059893, /* m/rad */
    EngineeringUnit_shake = 5059894, /* shake */
    EngineeringUnit_mile_per_minute_ = 5059895, /* mi/min */
    EngineeringUnit_mile_per_second_ = 5059896, /* mi/s */
    EngineeringUnit_metre_per_second_pascal = 5059897, /* (m/s)/Pa */
    EngineeringUnit_metre_per_hour = 5060144, /* m/h */
    EngineeringUnit_inch_per_year = 5060145, /* in/y */
    EngineeringUnit_kilometre_per_second_ = 5060146, /* km/s */
    EngineeringUnit_inch_per_minute = 5060147, /* in/min */
    EngineeringUnit_yard_per_second = 5060148, /* yd/s */
    EngineeringUnit_yard_per_minute = 5060149, /* yd/min */
    EngineeringUnit_yard_per_hour = 5060150, /* yd/h */
    EngineeringUnit_acre_foot__based_on_U_S__survey_foot_ = 5060151, /* acre-ft (US survey) */
    EngineeringUnit_cord__128_ft3_ = 5060152, /* cord */
    EngineeringUnit_cubic_mile__UK_statute_ = 5060153, /* mi³ */
    EngineeringUnit_micro_inch = 19767, /* µin */
    EngineeringUnit_ton__register_ = 5060400, /* RT */
    EngineeringUnit_cubic_metre_per_pascal = 5060401, /* m³/Pa */
    EngineeringUnit_bel = 5060402, /* B */
    EngineeringUnit_kilogram_per_cubic_metre_pascal = 5060403, /* (kg/m³)/Pa */
    EngineeringUnit_kilogram_per_pascal = 5060404, /* kg/Pa */
    EngineeringUnit_kilopound_force = 5060405, /* kip */
    EngineeringUnit_poundal = 5060406, /* pdl */
    EngineeringUnit_kilogram_metre_per_second_squared = 5060407, /* kg·m/s² */
    EngineeringUnit_pond = 5060408, /* p */
    EngineeringUnit_square_foot_per_hour_ = 5060409, /* ft²/h */
    EngineeringUnit_stokes_per_pascal = 5060656, /* St/Pa */
    EngineeringUnit_square_centimetre_per_second = 5060657, /* cm²/s */
    EngineeringUnit_square_metre_per_second_pascal = 5060658, /* (m²/s)/Pa */
    EngineeringUnit_denier_ = 5060659, /* den */
    EngineeringUnit_pound_per_yard_ = 5060660, /* lb/yd */
    EngineeringUnit_ton__assay = 5060661, /*  */
    EngineeringUnit_pfund = 5060662, /* pfd */
    EngineeringUnit_kilogram_per_second_pascal = 5060663, /* (kg/s)/Pa */
    EngineeringUnit_tonne_per_month = 5060664, /* t/mo */
    EngineeringUnit_tonne_per_year = 5060665, /* t/y */
    EngineeringUnit_million_Btu_per_1000_cubic_foot = 19769, /* MBTU/kft³ */
    EngineeringUnit_kilopound_per_hour = 5060912, /* klb/h */
    EngineeringUnit_pound_per_pound = 5060913, /* lb/lb */
    EngineeringUnit_pound_force_foot = 5060914, /* lbf·ft */
    EngineeringUnit_newton_metre_per_radian = 5060915, /* N·m/rad */
    EngineeringUnit_kilogram_metre = 5060916, /* kg·m */
    EngineeringUnit_poundal_foot = 5060917, /* pdl·ft */
    EngineeringUnit_poundal_inch = 5060918, /* pdl·in */
    EngineeringUnit_dyne_metre = 5060919, /* dyn·m */
    EngineeringUnit_kilogram_centimetre_per_second = 5060920, /* kg·(cm/s) */
    EngineeringUnit_gram_centimetre_per_second = 5060921, /* g·(cm/s) */
    EngineeringUnit_megavolt_ampere_reactive_hour = 5062984, /* Mvar·h */
    EngineeringUnit_megalitre = 5062988, /* Ml */
    EngineeringUnit_megametre = 5062989, /* Mm */
    EngineeringUnit_megavar = 5062994, /* kvar */
    EngineeringUnit_megawatt = 5062999, /* MW */
    EngineeringUnit_thousand_standard_brick_equivalent = 5063237, /*  */
    EngineeringUnit_thousand_board_foot = 5063238, /*  */
    EngineeringUnit_millibar = 5063250, /* mbar */
    EngineeringUnit_microgram = 19779, /* µg */
    EngineeringUnit_millicurie = 5063509, /* mCi */
    EngineeringUnit_air_dry_metric_ton = 19780, /*  */
    EngineeringUnit_milligram = 5064525, /* mg */
    EngineeringUnit_megahertz = 5064794, /* MHz */
    EngineeringUnit_square_mile__statute_mile_ = 5065035, /* mi² */
    EngineeringUnit_thousand = 5065036, /*  */
    EngineeringUnit_minute__unit_of_time_ = 5065038, /* min */
    EngineeringUnit_million = 5065039, /*  */
    EngineeringUnit_million_international_unit = 5065045, /*  */
    EngineeringUnit_milliard = 5065796, /*  */
    EngineeringUnit_millilitre = 5065812, /* ml */
    EngineeringUnit_square_millimetre = 5066059, /* mm² */
    EngineeringUnit_cubic_millimetre = 5066065, /* mm³ */
    EngineeringUnit_millimetre = 5066068, /* mm */
    EngineeringUnit_kilogram__dry_weight = 5066308, /*  */
    EngineeringUnit_month = 5066574, /* mo */
    EngineeringUnit_megapascal = 5066817, /* MPa */
    EngineeringUnit_cubic_metre_per_hour = 5067080, /* m³/h */
    EngineeringUnit_cubic_metre_per_second = 5067091, /* m³/s */
    EngineeringUnit_metre_per_second_squared = 5067595, /* m/s² */
    EngineeringUnit_square_metre = 5067851, /* m² */
    EngineeringUnit_cubic_metre = 5067857, /* m³ */
    EngineeringUnit_metre = 5067858, /* m */
    EngineeringUnit_metre_per_second = 5067859, /* m/s */
    EngineeringUnit_megavolt___ampere = 5068353, /* MV·A */
    EngineeringUnit_megawatt_hour__1000_kW_h_ = 5068616, /* MW·h */
    EngineeringUnit_pen_calorie = 20017, /*  */
    EngineeringUnit_pound_foot_per_second = 5124400, /* lb·(ft/s) */
    EngineeringUnit_pound_inch_per_second = 5124401, /* lb·(in/s) */
    EngineeringUnit_Pferdestaerke = 5124402, /* PS */
    EngineeringUnit_centimetre_of_mercury__0___C_ = 5124403, /* cmHg (0 ºC) */
    EngineeringUnit_centimetre_of_water__4___C_ = 5124404, /* cmH2O (4 °C) */
    EngineeringUnit_foot_of_water__39_2___F_ = 5124405, /* ftH2O (39,2 ºF) */
    EngineeringUnit_inch_of_mercury__32___F_ = 5124406, /* inHG (32 ºF) */
    EngineeringUnit_inch_of_mercury__60___F_ = 5124407, /* inHg (60 ºF) */
    EngineeringUnit_inch_of_water__39_2___F_ = 5124408, /* inH2O (39,2 ºF) */
    EngineeringUnit_inch_of_water__60___F_ = 5124409, /* inH2O (60 ºF) */
    EngineeringUnit_kip_per_square_inch = 5124656, /* ksi */
    EngineeringUnit_poundal_per_square_foot_ = 5124657, /* pdl/ft² */
    EngineeringUnit_ounce__avoirdupois__per_square_inch_ = 5124658, /* oz/in² */
    EngineeringUnit_conventional_metre_of_water = 5124659, /* mH2O */
    EngineeringUnit_gram_per_square_millimetre = 5124660, /* g/mm² */
    EngineeringUnit_pound_per_square_yard = 5124661, /* lb/yd² */
    EngineeringUnit_poundal_per_square_inch = 5124662, /* pdl/in² */
    EngineeringUnit_foot_to_the_fourth_power_ = 5124663, /* ft4 */
    EngineeringUnit_cubic_decimetre_per_kilogram = 5124664, /* dm³/kg */
    EngineeringUnit_cubic_foot_per_pound = 5124665, /* ft³/lb */
    EngineeringUnit_print_point = 20019, /*  */
    EngineeringUnit_cubic_inch_per_pound = 5124912, /* in³/lb */
    EngineeringUnit_kilonewton_per_metre = 5124913, /* kN/m */
    EngineeringUnit_poundal_per_inch = 5124914, /* pdl/in */
    EngineeringUnit_pound_force_per_yard = 5124915, /* lbf/yd */
    EngineeringUnit_poundal_second_per_square_foot_ = 5124916, /* (pdl/ft²)·s */
    EngineeringUnit_poise_per_pascal = 5124917, /* P/Pa */
    EngineeringUnit_newton_second_per_square_metre = 5124918, /* (N/m²)·s */
    EngineeringUnit_kilogram_per_metre_second = 5124919, /* kg/(m·s) */
    EngineeringUnit_kilogram_per_metre_minute = 5124920, /* kg/(m·min) */
    EngineeringUnit_kilogram_per_metre_day = 5124921, /* kg/(m·d) */
    EngineeringUnit_kilogram_per_metre_hour = 5125168, /* kg/(m·h) */
    EngineeringUnit_gram_per_centimetre_second = 5125169, /* g/(cm·s) */
    EngineeringUnit_poundal_second_per_square_inch = 5125170, /* (pdl/in²)·s */
    EngineeringUnit_pound_per_foot_minute = 5125171, /* lb/(ft·min) */
    EngineeringUnit_pound_per_foot_day = 5125172, /* lb/(ft·d) */
    EngineeringUnit_cubic_metre_per_second_pascal = 5125173, /* (m³/s)/Pa */
    EngineeringUnit_foot_poundal = 5125174, /* ft·pdl */
    EngineeringUnit_inch_poundal = 5125175, /* in·pdl */
    EngineeringUnit_watt_per_square_centimetre_ = 5125176, /* W/cm² */
    EngineeringUnit_watt_per_square_inch_ = 5125177, /* W/in² */
    EngineeringUnit_British_thermal_unit__international_table__per_square_foot_hour = 5125424, /* BtuIT/(ft²·h) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_square_foot_hour = 5125425, /* Btuth/(ft²·h) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_square_foot_minute = 5125426, /* Btuth/(ft²·min)  */
    EngineeringUnit_British_thermal_unit__international_table__per_square_foot_second = 5125427, /* BtuIT/(ft²·s) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_square_foot_second = 5125428, /* Btuth/(ft²·s) */
    EngineeringUnit_British_thermal_unit__international_table__per_square_inch_second = 5125429, /* BtuIT/(in²·s) */
    EngineeringUnit_calorie__thermochemical__per_square_centimetre_minute = 5125430, /* calth/(cm²·min) */
    EngineeringUnit_calorie__thermochemical__per_square_centimetre_second = 5125431, /* calth/(cm²·s) */
    EngineeringUnit_British_thermal_unit__international_table__per_cubic_foot_ = 5125432, /* BtuIT/ft³ */
    EngineeringUnit_British_thermal_unit__thermochemical__per_cubic_foot = 5125433, /* Btuth/ft³ */
    EngineeringUnit_British_thermal_unit__international_table__per_degree_Fahrenheit = 5125680, /* BtuIT/ºF */
    EngineeringUnit_British_thermal_unit__thermochemical__per_degree_Fahrenheit = 5125681, /* Btuth/ºF */
    EngineeringUnit_British_thermal_unit__international_table__per_degree_Rankine = 5125682, /* BtuIT/ºR */
    EngineeringUnit_British_thermal_unit__thermochemical__per_degree_Rankine = 5125683, /* Btuth/ºR */
    EngineeringUnit_British_thermal_unit__thermochemical__per_pound_degree_Rankine = 5125684, /* (Btuth/°R)/lb */
    EngineeringUnit_kilocalorie__international_table__per_gram_kelvin = 5125685, /* (kcalIT/K)/g */
    EngineeringUnit_British_thermal_unit__39___F__ = 5125686, /* Btu (39 ºF)  */
    EngineeringUnit_British_thermal_unit__59___F_ = 5125687, /* Btu (59 ºF) */
    EngineeringUnit_British_thermal_unit__60___F__ = 5125688, /* Btu (60 ºF)  */
    EngineeringUnit_calorie__20___C__ = 5125689, /* cal20 */
    EngineeringUnit_quad__1015_BtuIT_ = 5125936, /* quad */
    EngineeringUnit_therm__EC_ = 5125937, /* thm (EC) */
    EngineeringUnit_therm__U_S__ = 5125938, /* thm (US) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_pound = 5125939, /* Btuth/lb */
    EngineeringUnit_British_thermal_unit__international_table__per_hour_square_foot_degree_Fahrenheit = 5125940, /* BtuIT/(h·ft²·ºF) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_hour_square_foot_degree_Fahrenheit = 5125941, /* Btuth/(h·ft²·ºF) */
    EngineeringUnit_British_thermal_unit__international_table__per_second_square_foot_degree_Fahrenheit = 5125942, /* BtuIT/(s·ft²·ºF) */
    EngineeringUnit_British_thermal_unit__thermochemical__per_second_square_foot_degree_Fahrenheit = 5125943, /* Btuth/(s·ft²·ºF)  */
    EngineeringUnit_kilowatt_per_square_metre_kelvin = 5125944, /* kW/(m²·K) */
    EngineeringUnit_kelvin_per_pascal = 5125945, /* K/Pa */
    EngineeringUnit_watt_per_metre_degree_Celsius = 5126192, /* W/(m·°C) */
    EngineeringUnit_kilowatt_per_metre_kelvin = 5126193, /* kW/(m·K) */
    EngineeringUnit_kilowatt_per_metre_degree_Celsius = 5126194, /* kW/(m·°C) */
    EngineeringUnit_metre_per_degree_Celcius_metre = 5126195, /* m/(°C·m) */
    EngineeringUnit_degree_Fahrenheit_hour_per_British_thermal_unit__international_table_ = 5126196, /* ºF/(BtuIT/h) */
    EngineeringUnit_degree_Fahrenheit_hour_per_British_thermal_unit__thermochemical_ = 5126197, /* ºF/(Btuth/h) */
    EngineeringUnit_degree_Fahrenheit_second_per_British_thermal_unit__international_table_ = 5126198, /* ºF/(BtuIT/s) */
    EngineeringUnit_degree_Fahrenheit_second_per_British_thermal_unit__thermochemical_ = 5126199, /* ºF/(Btuth/s) */
    EngineeringUnit_degree_Fahrenheit_hour_square_foot_per_British_thermal_unit__international_table__inch = 5126200, /* ºF·h·ft²/(BtuIT·in) */
    EngineeringUnit_degree_Fahrenheit_hour_square_foot_per_British_thermal_unit__thermochemical__inch = 5126201, /* ºF·h·ft²/(Btuth·in) */
    EngineeringUnit_kilofarad = 5126448, /* kF */
    EngineeringUnit_reciprocal_joule = 5126449, /* 1/J */
    EngineeringUnit_picosiemens = 5126450, /* pS */
    EngineeringUnit_ampere_per_pascal = 5126451, /* A/Pa */
    EngineeringUnit_franklin = 5126452, /* Fr */
    EngineeringUnit_ampere_minute = 5126453, /* A·min */
    EngineeringUnit_biot = 5126454, /* Bi */
    EngineeringUnit_gilbert = 5126455, /* Gi */
    EngineeringUnit_volt_per_pascal = 5126456, /* V/Pa */
    EngineeringUnit_picovolt = 5126457, /* pV */
    EngineeringUnit_milligram_per_kilogram = 20033, /* mg/kg */
    EngineeringUnit_number_of_articles = 5128530, /*  */
    EngineeringUnit_number_of_cells = 5129036, /*  */
    EngineeringUnit_newton = 5129559, /* N */
    EngineeringUnit_message = 20038, /*  */
    EngineeringUnit_nil = 5130572, /* () */
    EngineeringUnit_number_of_international_units = 5130581, /*  */
    EngineeringUnit_load = 20044, /*  */
    EngineeringUnit_nautical_mile = 5131593, /* n mile */
    EngineeringUnit_number_of_packs = 5131600, /*  */
    EngineeringUnit_number_of_pairs = 5132370, /*  */
    EngineeringUnit_number_of_parts = 5132372, /*  */
    EngineeringUnit_mho = 20049, /*  */
    EngineeringUnit_micromho = 20050, /*  */
    EngineeringUnit_net_ton = 20052, /*  */
    EngineeringUnit_net_register_ton = 5133396, /*  */
    EngineeringUnit_newton_metre = 20053, /* N·m */
    EngineeringUnit_part_per_thousand = 20056, /* ‰ */
    EngineeringUnit_panel = 20289, /*  */
    EngineeringUnit_ozone_depletion_equivalent = 5194821, /*  */
    EngineeringUnit_ohm = 5195853, /* ? */
    EngineeringUnit_ounce_per_square_yard = 20302, /* oz/yd² */
    EngineeringUnit_ounce__avoirdupois_ = 5197402, /* oz */
    EngineeringUnit_overtime_hour = 20308, /*  */
    EngineeringUnit_ounce_av = 20314, /*  */
    EngineeringUnit_fluid_ounce__US_ = 5200449, /* fl oz (US) */
    EngineeringUnit_fluid_ounce__UK_ = 5200457, /* fl oz (UK) */
    EngineeringUnit_percent = 20529, /* % or pct */
    EngineeringUnit_coulomb_per_metre = 5255472, /* C/m */
    EngineeringUnit_kiloweber = 5255473, /* kWb */
    EngineeringUnit_gamma = 5255474, /* ? */
    EngineeringUnit_kilotesla = 5255475, /* kT */
    EngineeringUnit_joule_per_second = 5255476, /* J/s */
    EngineeringUnit_joule_per_minute = 5255477, /* J/min */
    EngineeringUnit_joule_per_hour = 5255478, /* J/h */
    EngineeringUnit_joule_per_day = 5255479, /* J/d */
    EngineeringUnit_kilojoule_per_second = 5255480, /* kJ/s */
    EngineeringUnit_kilojoule_per_minute = 5255481, /* kJ/min */
    EngineeringUnit_pound_per_foot = 20530, /* lb/ft */
    EngineeringUnit_kilojoule_per_hour = 5255728, /* kJ/h */
    EngineeringUnit_kilojoule_per_day = 5255729, /* kJ/d */
    EngineeringUnit_nanoohm = 5255730, /* n? */
    EngineeringUnit_ohm_circular_mil_per_foot_ = 5255731, /* O·cmil/ft  */
    EngineeringUnit_kilohenry = 5255732, /* kH */
    EngineeringUnit_lumen_per_square_foot_ = 5255733, /* lm/ft² */
    EngineeringUnit_phot = 5255734, /* ph */
    EngineeringUnit_footcandle = 5255735, /* ftc */
    EngineeringUnit_candela_per_square_inch_ = 5255736, /* cd/in² */
    EngineeringUnit_footlambert = 5255737, /* ftL */
    EngineeringUnit_lambert = 5255984, /* Lb */
    EngineeringUnit_stilb = 5255985, /* sb */
    EngineeringUnit_candela_per_square_foot = 5255986, /* cd/ft² */
    EngineeringUnit_kilocandela = 5255987, /* kcd */
    EngineeringUnit_millicandela = 5255988, /* mcd */
    EngineeringUnit_Hefner_Kerze = 5255989, /* HK */
    EngineeringUnit_international_candle_ = 5255990, /* IK */
    EngineeringUnit_British_thermal_unit__international_table__per_square_foot = 5255991, /* BtuIT/ft² */
    EngineeringUnit_British_thermal_unit__thermochemical__per_square_foot = 5255992, /* Btuth/ft² */
    EngineeringUnit_calorie__thermochemical__per_square_centimetre_ = 5255993, /* calth/cm² */
    EngineeringUnit_langley = 5256240, /* Ly */
    EngineeringUnit_decade__logarithmic_ = 5256241, /* dec */
    EngineeringUnit_pascal_squared_second = 5256242, /* Pa²·s */
    EngineeringUnit_bel_per_metre = 5256243, /* B/m */
    EngineeringUnit_pound_mole = 5256244, /* lbmol */
    EngineeringUnit_pound_mole_per_second = 5256245, /* lbmol/s */
    EngineeringUnit_pound_mole_per_minute = 5256246, /* lbmol/h */
    EngineeringUnit_kilomole_per_kilogram = 5256247, /* kmol/kg */
    EngineeringUnit_pound_mole_per_pound = 5256248, /* lbmol/lb */
    EngineeringUnit_newton_square_metre_per_ampere = 5256249, /* N·m²/A */
    EngineeringUnit_five_pack = 20533, /*  */
    EngineeringUnit_weber_metre = 5256496, /* Wb·m */
    EngineeringUnit_mol_per_kilogram_pascal = 5256497, /* (mol/kg)/Pa */
    EngineeringUnit_mol_per_cubic_metre_pascal = 5256498, /* (mol/m³)/Pa */
    EngineeringUnit_unit_pole_ = 5256499, /* unit pole  */
    EngineeringUnit_milligray_per_second = 5256500, /* mGy/s */
    EngineeringUnit_microgray_per_second = 5256501, /* µGy/s */
    EngineeringUnit_nanogray_per_second = 5256502, /* nGy/s */
    EngineeringUnit_gray_per_minute = 5256503, /* Gy/min */
    EngineeringUnit_milligray_per_minute = 5256504, /* mGy/min */
    EngineeringUnit_microgray_per_minute = 5256505, /* µGy/min */
    EngineeringUnit_nanogray_per_minute = 5256752, /* nGy/min */
    EngineeringUnit_gray_per_hour = 5256753, /* Gy/h */
    EngineeringUnit_milligray_per_hour = 5256754, /* mGy/h */
    EngineeringUnit_microgray_per_hour = 5256755, /* µGy/h */
    EngineeringUnit_nanogray_per_hour = 5256756, /* nGy/h */
    EngineeringUnit_sievert_per_second = 5256757, /* Sv/s */
    EngineeringUnit_millisievert_per_second = 5256758, /* mSv/s */
    EngineeringUnit_microsievert_per_second = 5256759, /* µSv/s */
    EngineeringUnit_nanosievert_per_second = 5256760, /* nSv/s */
    EngineeringUnit_rem_per_second = 5256761, /* rem/s */
    EngineeringUnit_sievert_per_hour = 5257008, /* Sv/h */
    EngineeringUnit_millisievert_per_hour = 5257009, /* mSv/h */
    EngineeringUnit_microsievert_per_hour = 5257010, /* µSv/h */
    EngineeringUnit_nanosievert_per_hour = 5257011, /* nSv/h */
    EngineeringUnit_sievert_per_minute = 5257012, /* Sv/min */
    EngineeringUnit_millisievert_per_minute = 5257013, /* mSv/min */
    EngineeringUnit_microsievert_per_minute = 5257014, /* µSv/min */
    EngineeringUnit_nanosievert_per_minute = 5257015, /* nSv/min */
    EngineeringUnit_reciprocal_square_inch = 5257016, /* 1/in² */
    EngineeringUnit_pascal_square_metre_per_kilogram = 5257017, /* Pa/(kg/m²) */
    EngineeringUnit_millipascal_per_metre = 5257264, /* mPa/m */
    EngineeringUnit_kilopascal_per_metre = 5257265, /* kPa/m */
    EngineeringUnit_hectopascal_per_metre = 5257266, /* hPa/m */
    EngineeringUnit_standard_atmosphere_per_metre = 5257267, /* Atm/m */
    EngineeringUnit_technical_atmosphere_per_metre = 5257268, /* at/m */
    EngineeringUnit_torr_per_metre = 5257269, /* Torr/m */
    EngineeringUnit_psi_per_inch = 5257270, /* psi/in */
    EngineeringUnit_cubic_metre_per_second_square_metre = 5257271, /* (m³/s)/m² */
    EngineeringUnit_rhe = 5257272, /* rhe */
    EngineeringUnit_pound_force_foot_per_inch = 5257273, /* lbf·ft/in */
    EngineeringUnit_pound_force_inch_per_inch_ = 5257520, /* lbf·in/in */
    EngineeringUnit_perm__0___C__ = 5257521, /* perm (0 ºC)  */
    EngineeringUnit_perm__23___C__ = 5257522, /* perm (23 ºC)  */
    EngineeringUnit_byte_per_second = 5257523, /* byte/s */
    EngineeringUnit_kilobyte_per_second = 5257524, /* kbyte/s */
    EngineeringUnit_megabyte_per_second = 5257525, /* Mbyte/s */
    EngineeringUnit_reciprocal_volt = 5257526, /* 1/V */
    EngineeringUnit_reciprocal_radian = 5257527, /* 1/rad */
    EngineeringUnit_pascal_to_the_power_sum_of_stoichiometric_numbers = 5257528, /* PaS?B */
    EngineeringUnit_mole_per_cubiv_metre_to_the_power_sum_of_stoichiometric_numbers = 5257529, /* (mol/m³)??B */
    EngineeringUnit_pascal = 5259596, /* Pa */
    EngineeringUnit_pad = 20548, /*  */
    EngineeringUnit_proof_litre = 5260876, /*  */
    EngineeringUnit_proof_gallon = 5261132, /*  */
    EngineeringUnit_pitch = 20553, /*  */
    EngineeringUnit_degree_Plato = 5262401, /* °P */
    EngineeringUnit_pound_per_inch_of_length = 20559, /* lb/in */
    EngineeringUnit_page_per_inch = 20561, /* ppi */
    EngineeringUnit_pair = 20562, /*  */
    EngineeringUnit_pound_force_per_square_inch = 20563, /* lbf/in² */
    EngineeringUnit_pint__US_ = 20564, /* pt (US) */
    EngineeringUnit_dry_pint__US_ = 5264452, /* dry pt (US) */
    EngineeringUnit_pint__UK_ = 5264457, /* pt (UK) */
    EngineeringUnit_liquid_pint__US_ = 5264460, /* liq pt (US) */
    EngineeringUnit_joule_per_tesla = 5321008, /* J/T */
    EngineeringUnit_erlang = 5321009, /* E */
    EngineeringUnit_octet = 5321010, /* o */
    EngineeringUnit_octet_per_second = 5321011, /* o/s */
    EngineeringUnit_shannon = 5321012, /* Sh */
    EngineeringUnit_hartley = 5321013, /* Hart */
    EngineeringUnit_natural_unit_of_information = 5321014, /* nat */
    EngineeringUnit_shannon_per_second = 5321015, /* Sh/s */
    EngineeringUnit_hartley_per_second = 5321016, /* Hart/s */
    EngineeringUnit_natural_unit_of_information_per_second = 5321017, /* nat/s */
    EngineeringUnit_second_per_kilogramm = 5321264, /* s/kg */
    EngineeringUnit_watt_square_metre = 5321265, /* W·m² */
    EngineeringUnit_second_per_radian_cubic_metre = 5321266, /* 1/(Hz·rad·m³) */
    EngineeringUnit_weber_to_the_power_minus_one = 5321267, /* 1/Wb */
    EngineeringUnit_reciprocal_inch = 5321268, /* 1/in */
    EngineeringUnit_dioptre = 5321269, /* dpt */
    EngineeringUnit_one_per_one = 5321270, /* 1/1 */
    EngineeringUnit_newton_metre_per_metre = 5321271, /* N·m/m² */
    EngineeringUnit_kilogram_per_square_metre_pascal_second = 5321272, /* kg/(m²·Pa·s) */
    EngineeringUnit_microgram_per_hectogram = 5321273, /* µg/hg */
    EngineeringUnit_meal = 20787, /*  */
    EngineeringUnit_pH__potential_of_Hydrogen_ = 5321520, /* pH */
    EngineeringUnit_page___facsimile = 20801, /*  */
    EngineeringUnit_quarter__of_a_year_ = 5325134, /*  */
    EngineeringUnit_page___hardcopy = 20802, /*  */
    EngineeringUnit_quire = 20818, /* qr */
    EngineeringUnit_quart__US_ = 20820, /* qt (US) */
    EngineeringUnit_dry_quart__US_ = 5329988, /* dry qt (US) */
    EngineeringUnit_quart__UK_ = 5329993, /* qt (UK) */
    EngineeringUnit_liquid_quart__US_ = 5329996, /* liq qt (US) */
    EngineeringUnit_quarter__UK_ = 5330002, /* Qr (UK) */
    EngineeringUnit_pica = 21041, /*  */
    EngineeringUnit_thousand_cubic_metre = 21049, /*  */
    EngineeringUnit_running_or_operating_hour = 21064, /*  */
    EngineeringUnit_ream = 21069, /*  */
    EngineeringUnit_room = 5394253, /*  */
    EngineeringUnit_pound_per_ream = 21072, /*  */
    EngineeringUnit_revolutions_per_minute = 5394509, /* r/min */
    EngineeringUnit_revolutions_per_second = 5394515, /* r/s */
    EngineeringUnit_revenue_ton_mile = 21076, /*  */
    EngineeringUnit_square_foot_per_second = 21299, /* ft²/s */
    EngineeringUnit_square_metre_per_second = 21300, /* m²/s */
    EngineeringUnit_half_year__6_months_ = 5456206, /*  */
    EngineeringUnit_score = 5456719, /*  */
    EngineeringUnit_scruple = 5456722, /*  */
    EngineeringUnit_second__unit_of_time_ = 5457219, /* s */
    EngineeringUnit_set = 5457236, /*  */
    EngineeringUnit_segment = 21319, /*  */
    EngineeringUnit_shipping_ton = 5458004, /*  */
    EngineeringUnit_siemens = 5458245, /* S */
    EngineeringUnit_mile__statute_mile_ = 5459273, /* mile */
    EngineeringUnit_square = 21329, /*  */
    EngineeringUnit_square__roofing = 5460306, /*  */
    EngineeringUnit_strip = 21330, /*  */
    EngineeringUnit_stick = 5461059, /*  */
    EngineeringUnit_stone__UK_ = 5461065, /* st */
    EngineeringUnit_stick__cigarette = 5461067, /*  */
    EngineeringUnit_standard_litre = 5461068, /*  */
    EngineeringUnit_ton__US__or_short_ton__UK_US_ = 5461070, /* ton (US) */
    EngineeringUnit_straw = 5461079, /*  */
    EngineeringUnit_skein = 21335, /*  */
    EngineeringUnit_shipment = 21336, /*  */
    EngineeringUnit_syringe = 5462354, /*  */
    EngineeringUnit_telecommunication_line_in_service = 21552, /*  */
    EngineeringUnit_thousand_piece = 21555, /*  */
    EngineeringUnit_kiloampere_hour__thousand_ampere_hour_ = 5521736, /* kA·h */
    EngineeringUnit_total_acid_number = 5521742, /* TAN */
    EngineeringUnit_thousand_square_inch = 21577, /*  */
    EngineeringUnit_metric_ton__including_container = 5523779, /*  */
    EngineeringUnit_metric_ton__including_inner_packaging = 5523792, /*  */
    EngineeringUnit_tonne_kilometre = 5524301, /* t·km */
    EngineeringUnit_kilogram_of_imported_meat__less_offal = 5524819, /*  */
    EngineeringUnit_tonne__metric_ton_ = 5525061, /* t */
    EngineeringUnit_ten_pack = 21584, /*  */
    EngineeringUnit_ten_pair = 5525586, /*  */
    EngineeringUnit_thousand_cubic_metre_per_day = 5525828, /* km³/d */
    EngineeringUnit_trillion__EUR_ = 5526092, /*  */
    EngineeringUnit_ten_set = 5526356, /*  */
    EngineeringUnit_ten_thousand_sticks = 5526611, /*  */
    EngineeringUnit_treatment = 21809, /*  */
    EngineeringUnit_tablet = 21810, /*  */
    EngineeringUnit_torr = 21825, /* Torr */
    EngineeringUnit_telecommunication_line_in_service_average = 21826, /*  */
    EngineeringUnit_telecommunication_port = 21827, /*  */
    EngineeringUnit_volt___ampere_per_kilogram = 22081, /* V·A / kg */
    EngineeringUnit_volt = 5655636, /* V */
    EngineeringUnit_percent_volume = 22096, /*  */
    EngineeringUnit_wet_kilo = 22322, /*  */
    EngineeringUnit_watt_per_kilogram = 22337, /* W/kg */
    EngineeringUnit_wet_pound = 22338, /*  */
    EngineeringUnit_cord = 5718852, /*  */
    EngineeringUnit_wet_ton = 22341, /*  */
    EngineeringUnit_weber = 5719362, /* Wb */
    EngineeringUnit_week = 5719365, /* wk */
    EngineeringUnit_wine_gallon = 22343, /*  */
    EngineeringUnit_watt_hour = 5720146, /* W·h */
    EngineeringUnit_working_month = 22349, /*  */
    EngineeringUnit_standard = 5722948, /* std */
    EngineeringUnit_watt = 5723220, /* W */
    EngineeringUnit_millilitre_of_water = 22359, /*  */
    EngineeringUnit_Gunter_s_chain = 22577, /* ch (UK) */
    EngineeringUnit_square_yard = 5850187, /* yd² */
    EngineeringUnit_cubic_yard = 5850193, /* yd³ */
    EngineeringUnit_yard = 5853764, /* yd */
    EngineeringUnit_hanging_container = 5910833, /*  */
    EngineeringUnit_page = 23120, /*  */
    EngineeringUnit_mutually_defined = 23130, /*  */
    NoOfUnits = 1781
};

    UaEUInformation();
    UaEUInformation(const UaEUInformation &other);
    UaEUInformation(const OpcUa_EUInformation &other);
    UaEUInformation(
        const UaString& namespaceUri,
        OpcUa_Int32 unitId,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description
        );
    UaEUInformation(const UaExtensionObject &extensionObject);
    UaEUInformation(const OpcUa_ExtensionObject &extensionObject);
    UaEUInformation(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaEUInformation(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    UaEUInformation(EngineeringUnit unitId);
    ~UaEUInformation();

    void clear();

    bool operator==(const UaEUInformation &other) const;
    bool operator!=(const UaEUInformation &other) const;

    UaEUInformation& operator=(const UaEUInformation &other);

    OpcUa_EUInformation* copy() const;
    void copyTo(OpcUa_EUInformation *pDst) const;

    static OpcUa_EUInformation* clone(const OpcUa_EUInformation& source);
    static void cloneTo(const OpcUa_EUInformation& source, OpcUa_EUInformation& copy);

    void attach(OpcUa_EUInformation *pValue);
    OpcUa_EUInformation* detach(OpcUa_EUInformation* pDst);

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    void toExtensionObject(UaExtensionObject &extensionObject) const;
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject) const;
    void toExtensionObject(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    void toExtensionObject(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    OpcUa_StatusCode setEUInformation(const UaExtensionObject &extensionObject);
    OpcUa_StatusCode setEUInformation(const OpcUa_ExtensionObject &extensionObject);
    OpcUa_StatusCode setEUInformation(UaExtensionObject &extensionObject, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEUInformation(OpcUa_ExtensionObject &extensionObject, OpcUa_Boolean bDetach);

    void setEUInformation(
        const UaString& namespaceUri,
        OpcUa_Int32 unitId,
        const UaLocalizedText& displayName,
        const UaLocalizedText& description
        );

    void setEUInformation(EngineeringUnit unitId);
    static UaEUInformation fromUnitId(EngineeringUnit unitId);

    UaString getNamespaceUri() const;
    OpcUa_Int32 getUnitId() const;
    UaLocalizedText getDisplayName() const;
    UaLocalizedText getDescription() const;

    void setNamespaceUri(const UaString& namespaceUri);
    void setUnitId(OpcUa_Int32 unitId);
    void setDisplayName(const UaLocalizedText& displayName);
    void setDescription(const UaLocalizedText& description);
};

/** @ingroup CppBaseLibraryClass
 *  @brief Array class for the UA stack structure OpcUa_EUInformation.
 *
 *  This class encapsulates an array of the native OpcUa_EUInformation structure
 *  and handles memory allocation and cleanup for you.
 *  @see UaEUInformation for information about the encapsulated structure.
 */
class UABASE_EXPORT UaEUInformations
{
public:
    UaEUInformations();
    UaEUInformations(const UaEUInformations &other);
    UaEUInformations(OpcUa_Int32 length, OpcUa_EUInformation* data);
    virtual ~UaEUInformations();

    UaEUInformations& operator=(const UaEUInformations &other);
    const OpcUa_EUInformation& operator[](OpcUa_UInt32 index) const;
    OpcUa_EUInformation& operator[](OpcUa_UInt32 index);

    bool operator==(const UaEUInformations &other) const;
    bool operator!=(const UaEUInformations &other) const;

    void attach(OpcUa_UInt32 length, OpcUa_EUInformation* data);
    void attach(OpcUa_Int32 length, OpcUa_EUInformation* data);
    OpcUa_EUInformation* detach();

    void create(OpcUa_UInt32 length);
    void resize(OpcUa_UInt32 length);
    void clear();

    inline OpcUa_UInt32 length() const {return m_noOfElements;}
    inline const OpcUa_EUInformation* rawData() const {return m_data;}
    inline OpcUa_EUInformation* rawData() {return m_data;}

    void toVariant(UaVariant &variant) const;
    void toVariant(OpcUa_Variant &variant) const;
    void toVariant(UaVariant &variant, OpcUa_Boolean bDetach);
    void toVariant(OpcUa_Variant &variant, OpcUa_Boolean bDetach);

    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean updateTimeStamps) const;
    void toDataValue(UaDataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);
    void toDataValue(OpcUa_DataValue &dataValue, OpcUa_Boolean bDetach, OpcUa_Boolean updateTimeStamps);

    OpcUa_StatusCode setEUInformations(const UaVariant &variant);
    OpcUa_StatusCode setEUInformations(const OpcUa_Variant &variant);
    OpcUa_StatusCode setEUInformations(UaVariant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEUInformations(OpcUa_Variant &variant, OpcUa_Boolean bDetach);
    OpcUa_StatusCode setEUInformations(OpcUa_Int32 length, OpcUa_EUInformation* data);

private:
    OpcUa_UInt32 m_noOfElements;
    OpcUa_EUInformation* m_data;
};

#endif // UAEUINFORMATION_H

