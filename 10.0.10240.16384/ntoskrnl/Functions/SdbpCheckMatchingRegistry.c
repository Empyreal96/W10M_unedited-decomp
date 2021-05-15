// SdbpCheckMatchingRegistry 
 
int __fastcall SdbpCheckMatchingRegistry(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r5
  int v9; // [sp+4h] [bp-54h]
  int v10; // [sp+20h] [bp-38h] BYREF
  int v11; // [sp+24h] [bp-34h] BYREF
  int v12; // [sp+28h] [bp-30h] BYREF
  int v13; // [sp+2Ch] [bp-2Ch] BYREF
  int v14; // [sp+30h] [bp-28h] BYREF
  int v15; // [sp+34h] [bp-24h] BYREF
  int v16; // [sp+38h] [bp-20h] BYREF
  int v17; // [sp+3Ch] [bp-1Ch] BYREF
  int v18; // [sp+40h] [bp-18h] BYREF
  int v19; // [sp+44h] [bp-14h]

  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v18 = 0;
  v19 = 0;
  v10 = 0;
  v11 = 0;
  *a1 = 0;
  v7 = 0;
  if ( SdbpGetRegistryMatchingAttributes(a3, a5, &v16, &v15, &v14, &v13, &v12, &v18, &v11, &v10) )
  {
    if ( SdbpCheckMatchingRegistryEntry(v16, v15, v14, v13, v12, v9, v18, v19, v11, v10, &v17) )
    {
      v7 = 1;
      *(_DWORD *)(a6 + 40) = 1;
      *a1 = v17;
    }
    else
    {
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistry", 1240, "Failed to check MATCHING_REG entry");
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistry", 1223, "Failed to read MATCHING_REG entry");
  }
  return v7;
}
