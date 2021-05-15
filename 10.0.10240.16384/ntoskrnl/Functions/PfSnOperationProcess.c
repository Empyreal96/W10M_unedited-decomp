// PfSnOperationProcess 
 
int __fastcall PfSnOperationProcess(unsigned __int8 *a1)
{
  int v2; // r3
  unsigned __int16 *v3; // r6
  int v4; // r2
  int v5; // r3
  bool v6; // zf
  int v7; // r4
  int v8; // r7
  int v9; // r4
  unsigned int v10; // r1
  unsigned __int16 *v12; // [sp+8h] [bp-70h] BYREF
  int v13; // [sp+Ch] [bp-6Ch] BYREF
  int v14; // [sp+10h] [bp-68h] BYREF
  int v15[24]; // [sp+18h] [bp-60h] BYREF

  v2 = *a1;
  v3 = 0;
  v12 = 0;
  if ( v2 != 1 || (v4 = a1[1], (v4 & 0xFFFFFFFE) != 0) || *((_WORD *)a1 + 1) )
  {
    v7 = -1073741811;
  }
  else
  {
    v5 = *((_DWORD *)a1 + 1);
    if ( (v4 & 1) != 0 )
    {
      v6 = (v5 & 0xFFFFFFFE) == 0;
    }
    else
    {
      if ( (v5 & 4) != 0 && ((v5 & 2) != 0 || (v5 & 1) != 0) )
        return -1073741811;
      v6 = (v5 & 0xFFFFFFF8) == 0;
    }
    if ( !v6 )
      return -1073741811;
    if ( PfSnCheckScenario(1, &v13) < 0 )
      return 0;
    v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v7 = PfCalculateProcessHash(v8, &v12);
    v3 = v12;
    if ( v7 >= 0 )
    {
      v9 = PfSnFindImageFileName(v12, &v14);
      if ( v9 )
      {
        memset(v15, 0, 64);
        RtlStringCbPrintfW(v15, 0x3Cu, (int)L"Op-%.17s-%08X", v9);
        v15[15] = *((_DWORD *)a1 + 2);
        if ( (a1[1] & 1) != 0 )
        {
          if ( (*((_DWORD *)a1 + 1) & 1) != 0 )
            v10 = 9;
          else
            v10 = 8;
          PfSnEndProcessTrace(v8, v10, (int)v15);
        }
        else
        {
          PfSnBeginScenario();
        }
        v7 = 0;
      }
      else
      {
        v7 = -1073741595;
      }
    }
  }
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v7;
}
