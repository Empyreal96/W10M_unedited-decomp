// PiSwDeviceMakeCompatibleIds 
 
int __fastcall PiSwDeviceMakeCompatibleIds(int a1, int *a2)
{
  unsigned __int16 *v3; // r4
  int v4; // r5
  int v6; // r9
  int v7; // r0
  int v8; // r7
  unsigned __int16 *v9; // r5
  int v10; // r4
  unsigned int v12; // r7
  unsigned int v13; // r8

  v3 = *(unsigned __int16 **)(a1 + 20);
  v4 = 0;
  v6 = 0;
  if ( v3 )
  {
    while ( *v3 )
    {
      v12 = wcslen(v3) + 1;
      if ( wcsicmp((int)v3, L"SWD\\GenericRaw") && wcsicmp((int)v3, L"SWD\\Generic") )
        v4 += 2 * v12;
      v3 += v12;
    }
  }
  if ( (*(_DWORD *)(a1 + 36) & 8) == 0 )
    v4 += 30;
  v7 = ExAllocatePoolWithTag(1, v4 + 26, 1466986064);
  v8 = v7;
  if ( v7 )
  {
    v9 = *(unsigned __int16 **)(a1 + 20);
    v10 = v7;
    if ( v9 )
    {
      while ( *v9 )
      {
        v13 = wcslen(v9) + 1;
        if ( wcsicmp((int)v9, L"SWD\\GenericRaw") && wcsicmp((int)v9, L"SWD\\Generic") )
        {
          memmove(v10, (int)v9, 2 * v13);
          v10 += 2 * v13;
        }
        v9 += v13;
      }
    }
    if ( (*(_DWORD *)(a1 + 36) & 8) == 0 )
    {
      memmove(v10, (int)L"SWD\\GenericRaw", 0x1Eu);
      v10 += 30;
    }
    memmove(v10, (int)L"SWD\\Generic", 0x18u);
    *(_WORD *)(v10 + 24) = 0;
  }
  else
  {
    v6 = -1073741670;
  }
  *a2 = v8;
  return v6;
}
