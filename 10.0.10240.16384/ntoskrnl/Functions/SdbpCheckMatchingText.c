// SdbpCheckMatchingText 
 
int __fastcall SdbpCheckMatchingText(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // r6
  int v9; // r0
  unsigned int v10; // r5
  unsigned int v12; // [sp+18h] [bp-30h] BYREF
  int v13; // [sp+1Ch] [bp-2Ch] BYREF
  int v14; // [sp+20h] [bp-28h] BYREF
  int v15; // [sp+24h] [bp-24h] BYREF
  int v16; // [sp+28h] [bp-20h] BYREF
  int v17; // [sp+2Ch] [bp-1Ch] BYREF
  int v18[6]; // [sp+30h] [bp-18h] BYREF

  v17 = 0;
  v18[0] = 0;
  v15 = 0;
  v16 = 0;
  v12 = 0;
  v14 = 0;
  v13 = 0x2000;
  *a1 = 0;
  v8 = 0;
  v9 = SdbpGetMatchingTextAttributes(a3, a5, &v16, &v12, &v15, &v14, &v13);
  v10 = v12;
  if ( v9 )
  {
    if ( SdbpCheckMatchingTextEntry(a2, a6, v16, v12, v15, v14, v13, v18, &v17) )
    {
      v8 = 1;
      *(_DWORD *)(a6 + 40) |= v17;
      *a1 = v18[0];
    }
    else
    {
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingText", 1702, "Failed to check MATCHING_TEXT entry");
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpCheckMatchingText", 1685, "Failed to read MATCHING_TEXT entry");
  }
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v8;
}
