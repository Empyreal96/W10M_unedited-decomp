// WheapSqmIncrementDword 
 
int __fastcall WheapSqmIncrementDword(int a1)
{
  return WheapSqmDwordCommon(6, (int)WHEA_SQM_EVENT_INCREMENTDWORD, a1, 1);
}
