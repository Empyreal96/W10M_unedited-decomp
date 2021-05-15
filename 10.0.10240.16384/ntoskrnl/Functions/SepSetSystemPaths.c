// SepSetSystemPaths 
 
int __fastcall SepSetSystemPaths(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r6
  int v6; // r0
  unsigned int v7; // r4
  unsigned int v8; // r0
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = a4;
  SepLoadNgenLocations();
  v4 = RtlStringCbLengthW(-28624, 0x208u, v10);
  if ( v4 >= 0 )
  {
    v5 = v10[0];
    v6 = ExAllocatePoolWithTag(1, v10[0] + 46, 1668499779);
    v7 = v6;
    if ( v6 )
    {
      RtlStringCbPrintfW((_WORD *)(v6 + 16), v5 + 30, (int)L"\\??\\%ws\\System32\\", -28624);
      RtlInitUnicodeString(v7, (unsigned __int16 *)(v7 + 16));
      *(_DWORD *)(v7 + 8) = *(_DWORD *)v7;
      *(_DWORD *)(v7 + 12) = *(_DWORD *)(v7 + 4);
      *(_WORD *)(v7 + 8) = 12;
      __dmb(0xBu);
      do
        v8 = __ldrex((unsigned int *)&dword_646664);
      while ( !v8 && __strex(v7, (unsigned int *)&dword_646664) );
      if ( !v8 )
        v7 = 0;
      if ( v7 )
        return sub_816560();
    }
    else
    {
      v4 = -1073741801;
    }
  }
  return v4;
}
