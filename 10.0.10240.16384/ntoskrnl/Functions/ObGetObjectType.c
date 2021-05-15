// ObGetObjectType 
 
int __fastcall ObGetObjectType(int a1)
{
  return ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
}
