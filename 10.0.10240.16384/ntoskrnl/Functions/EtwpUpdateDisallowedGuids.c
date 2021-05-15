// EtwpUpdateDisallowedGuids 
 
int __fastcall EtwpUpdateDisallowedGuids(unsigned __int16 *a1, unsigned int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v11; // r0
  unsigned int v12; // r6
  unsigned int v13; // r5
  unsigned int v14; // r4
  _DWORD *v15; // r4
  _DWORD *v16; // r9
  _DWORD *v17; // r5
  unsigned int v18; // r10
  int v19; // r0
  unsigned int v20; // r0

  if ( a2 > 0x200 )
    return -1073741811;
  if ( a2 )
  {
    v11 = ExAllocatePoolWithTag(1, 16 * a2, 1685550149);
    v12 = v11;
    if ( !v11 )
      return -1073741670;
    memmove(v11, a3, 16 * a2);
    qsort(v12, a2, 0x10u, (int (__fastcall *)(unsigned int, _BYTE *))EtwpCompareGuid);
    v13 = 0;
    if ( a2 != 1 )
    {
      v14 = v12;
      while ( memcmp(v14, v14 + 16, 16) )
      {
        ++v13;
        v14 += 16;
        if ( v13 >= a2 - 1 )
          goto LABEL_13;
      }
      ExFreePoolWithTag(v12);
      return -1073741811;
    }
  }
  else
  {
    v12 = 0;
  }
LABEL_13:
  if ( *a1 )
  {
    v15 = (_DWORD *)*((_DWORD *)a1 + 1);
    v16 = &v15[4 * *a1];
  }
  else
  {
    v15 = 0;
    v16 = 0;
  }
  if ( a2 )
  {
    v17 = (_DWORD *)v12;
    v18 = v12 + 16 * a2;
  }
  else
  {
    v17 = 0;
    v18 = 0;
  }
  if ( v15 < v16 )
  {
    while ( 1 )
    {
      if ( (unsigned int)v17 >= v18 )
      {
LABEL_30:
        while ( v15 < v16 )
        {
          EtwpDisallowedGuidRemoval(v15, (int)a7);
          v15 += 4;
        }
        goto LABEL_33;
      }
      v19 = memcmp((unsigned int)v15, (unsigned int)v17, 16);
      if ( !v19 )
        break;
      if ( v19 >= 0 )
      {
        EtwpDisallowedGuidAddition(v17, a7);
        goto LABEL_26;
      }
      EtwpDisallowedGuidRemoval(v15, (int)a7);
      v15 += 4;
LABEL_27:
      if ( v15 >= v16 )
        goto LABEL_30;
    }
    v15 += 4;
LABEL_26:
    v17 += 4;
    goto LABEL_27;
  }
LABEL_33:
  while ( (unsigned int)v17 < v18 )
  {
    EtwpDisallowedGuidAddition(v17, a7);
    v17 += 4;
  }
  v20 = *((_DWORD *)a1 + 1);
  *a1 = a2;
  if ( v20 )
    ExFreePoolWithTag(v20);
  *((_DWORD *)a1 + 1) = v12;
  return 0;
}
