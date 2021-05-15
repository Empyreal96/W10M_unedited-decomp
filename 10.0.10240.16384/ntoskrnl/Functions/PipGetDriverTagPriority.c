// PipGetDriverTagPriority 
 
unsigned int __fastcall PipGetDriverTagPriority(int a1, _DWORD *a2)
{
  unsigned int i; // r5
  _DWORD *v4; // r6
  unsigned int v5; // r1
  int v6; // r7
  int v7; // r4
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r3
  unsigned int v12; // r1
  int *v13; // r2
  int v14; // t1
  int v15; // [sp+0h] [bp-20h] BYREF
  _DWORD *v16; // [sp+4h] [bp-1Ch] BYREF
  __int16 v17; // [sp+8h] [bp-18h]
  __int16 v18; // [sp+Ah] [bp-16h]
  unsigned __int16 *v19; // [sp+Ch] [bp-14h]

  v15 = a1;
  v16 = a2;
  v18 = 132;
  v17 = 130;
  v19 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GroupOrderList";
  i = 0xFFFF;
  if ( IopOpenRegistryKeyEx(&v15) < 0 )
    return i;
  if ( IopGetRegistryValue(a1, L"Group", 0, (int *)&v16) < 0 )
  {
LABEL_8:
    ZwClose();
    return i;
  }
  v4 = v16;
  if ( v16[1] == 1 )
  {
    v5 = v16[3];
    if ( v5 )
    {
      PnpRegSzToString((char *)v16 + v16[2], v5, &v16);
      v17 = (__int16)v16;
      v18 = v4[3];
      v19 = (unsigned __int16 *)((char *)v4 + v4[2]);
    }
  }
  v6 = 0;
  v7 = IopGetRegistryValue(a1, L"Tag", 80, (int *)&v16);
  if ( v7 < 0
    || (v16[1] != 4 || v16[3] != 4 ? (v7 = -1073741823) : (v6 = *(_DWORD *)((char *)v16 + v16[2])),
        ExFreePoolWithTag((unsigned int)v16),
        v7 < 0) )
  {
    ExFreePoolWithTag((unsigned int)v4);
    goto LABEL_8;
  }
  v9 = IopGetRegistryValue(v15, v19, 80, (int *)&v16);
  ExFreePoolWithTag((unsigned int)v4);
  ZwClose();
  if ( v9 >= 0 )
  {
    if ( v16[1] == 3 )
    {
      v10 = v16[3];
      if ( v10 >= 4 )
      {
        v11 = v16[2];
        v12 = *(_DWORD *)((char *)v16 + v11);
        if ( 4 * (v12 + 1) <= v10 )
        {
          v13 = (_DWORD *)((char *)v16 + v11 + 4);
          for ( i = 1; i <= v12; i = (unsigned __int16)(i + 1) )
          {
            v14 = *v13++;
            if ( v6 == v14 )
              break;
          }
        }
      }
    }
    ExFreePoolWithTag((unsigned int)v16);
  }
  return i;
}
