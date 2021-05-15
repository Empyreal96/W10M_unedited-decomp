// WheapSqmSetDword 
 
int __fastcall WheapSqmSetDword(int a1, int a2)
{
  return WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, a1, a2);
}
