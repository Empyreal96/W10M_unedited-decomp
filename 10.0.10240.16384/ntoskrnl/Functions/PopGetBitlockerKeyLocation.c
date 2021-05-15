// PopGetBitlockerKeyLocation 
 
int __fastcall PopGetBitlockerKeyLocation(int *a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r0
  char *v5; // r0
  _WORD *v6; // r0
  unsigned int v7; // r3
  unsigned int v8; // t1
  int v9; // r2
  int v10; // r6
  char v12[8]; // [sp+10h] [bp-50h] BYREF
  int v13; // [sp+18h] [bp-48h]
  int v14; // [sp+1Ch] [bp-44h]
  char *v15; // [sp+20h] [bp-40h]
  int v16; // [sp+24h] [bp-3Ch]
  int v17; // [sp+28h] [bp-38h]
  int v18; // [sp+2Ch] [bp-34h]
  char v19[8]; // [sp+30h] [bp-30h] BYREF
  int v20; // [sp+3Ch] [bp-24h]

  v2 = 0;
  RtlInitUnicodeString((unsigned int)v19, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control");
  v13 = 24;
  v14 = 0;
  v16 = 576;
  v15 = v19;
  v17 = 0;
  v18 = 0;
  v3 = ZwOpenKey();
  if ( v3 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v12, L"SystemStartOptions");
    v4 = ZwQueryValueKey();
    v3 = v4;
    if ( v4 >= 0 || v4 == -2147483643 )
    {
      if ( v20 != 1 )
        return -1073741811;
      v2 = ExAllocatePoolWithTag(512, 2, 1718968931);
      if ( !v2 )
        return -1073741801;
      v3 = ZwQueryValueKey();
    }
    if ( v3 >= 0 )
    {
      *(_WORD *)(*(_DWORD *)(v2 + 8) + v2 + 12) = 0;
      v5 = wcsstr((char *)(v2 + 12), (char *)L"FVEBOOT=");
      if ( !v5 )
        goto LABEL_11;
      v8 = *((unsigned __int16 *)v5 + 8);
      v6 = v5 + 16;
      v7 = v8;
      v9 = 0;
      v10 = 0;
      while ( v7 >= 0x30 && v7 <= 0x39 )
      {
        v10 = (10 * __PAIR64__(v10, v9) + (int)(v7 - 48)) >> 32;
        v9 = 10 * v9 + v7 - 48;
        v7 = (unsigned __int16)*++v6;
      }
      if ( !*v6 || *v6 == 32 )
      {
        *a1 = v9;
        a1[1] = v10;
      }
      else
      {
LABEL_11:
        v3 = -1073741823;
      }
    }
    if ( v2 )
      ExFreePoolWithTag(v2);
  }
  return v3;
}
