// PiDevCfgQueryResolveValue 
 
int __fastcall PiDevCfgQueryResolveValue(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r6
  _DWORD *v7; // r4
  int v8; // r2
  unsigned int v9; // r3
  unsigned __int16 *i; // r5
  _WORD *v12; // r2
  int v13; // r3
  _DWORD *v14; // r7
  _DWORD *v15; // r0
  _DWORD *v16; // r5
  int v18[2]; // [sp+0h] [bp-28h] BYREF
  int v19; // [sp+8h] [bp-20h] BYREF
  _DWORD *v20; // [sp+Ch] [bp-1Ch]

  v18[1] = a2;
  v19 = a3;
  v20 = a4;
  v18[0] = 0;
  v6 = IopGetRegistryValue(a2, a3, 0, v18);
  v7 = (_DWORD *)v18[0];
  if ( v6 >= 0 )
  {
    *(_WORD *)(v18[0] + 6) = 0;
    if ( !*(_DWORD *)(a1 + 8) )
      goto LABEL_26;
    v8 = v7[1];
    if ( v8 != 1 && v8 != 2 )
      goto LABEL_26;
    v9 = v7[3];
    if ( v9 < 2 || *(_WORD *)((char *)v7 + 2 * (v9 >> 1) + v7[2] - 2) )
      goto LABEL_26;
    i = 0;
    v12 = (_WORD *)((char *)v7 + v7[2]);
    if ( *v12 == 36 )
    {
      for ( i = v12 + 1; ; ++i )
      {
        v13 = *i;
        if ( !*i )
          break;
        if ( v13 != 63 && v13 != 33 && v13 != 43 && v13 != 45 )
        {
          if ( *i == 36 )
            ++i;
          break;
        }
      }
    }
    RtlInitUnicodeString((unsigned int)&v19, i);
    if ( i )
    {
      v6 = PiDevCfgResolveVariable(a1, v20, v18);
      if ( v6 >= 0 )
      {
        v14 = (_DWORD *)v18[0];
        v15 = (_DWORD *)ExAllocatePoolWithTag(1, *(_DWORD *)(v18[0] + 20) + v7[4] + 26);
        v16 = v15;
        if ( v15 )
        {
          *v15 = *v7;
          v15[4] = v7[4];
          v15[1] = v14[4];
          v15[3] = v14[5];
          v15[2] = v7[4] + 22;
          memmove((int)(v15 + 5), (int)(v7 + 5), v7[4]);
          *((_WORD *)v7 + (v7[4] >> 1) + 10) = 0;
          memmove((int)v16 + v16[2], v14[6], v14[5]);
          *a4 = v16;
        }
        else
        {
          v6 = -1073741670;
        }
      }
    }
    else
    {
LABEL_26:
      *a4 = v7;
      v7 = 0;
    }
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v6;
}
