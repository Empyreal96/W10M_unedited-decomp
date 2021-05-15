// PiQueryDeviceRelations 
 
int __fastcall PiQueryDeviceRelations(int a1, int a2, int *a3, int a4)
{
  _WORD *v4; // r9
  int *v5; // r7
  int v6; // r5
  int v7; // r10
  int v9; // r4
  int v10; // r0
  int v11; // r8
  int v12; // r6
  int v13; // r2
  _DWORD *v14; // r3
  unsigned int v15; // r4
  unsigned int *v16; // r0
  _DWORD *v17; // r6
  unsigned int i; // r7
  unsigned int *v19; // r2
  unsigned int v20; // r6
  int v21; // r4
  unsigned int v22; // r2
  _WORD *v23; // r9
  unsigned int *v25; // [sp+0h] [bp-28h] BYREF
  int *v26; // [sp+4h] [bp-24h]
  int v27; // [sp+8h] [bp-20h]

  v27 = a4;
  v4 = (_WORD *)a4;
  v5 = a3;
  v6 = 0;
  v25 = 0;
  v26 = a3;
  v7 = 0;
  if ( a2 )
  {
    switch ( a2 )
    {
      case 1:
        v9 = 3;
        break;
      case 2:
        v9 = 2;
        break;
      case 3:
        v9 = 0;
        break;
      case 4:
        v9 = 6;
        break;
      default:
        return -1073741811;
    }
  }
  else
  {
    v9 = 1;
  }
  PpDevNodeLockTree(0, a2);
  v10 = PnpDeviceObjectFromDeviceInstance(a1);
  v11 = v10;
  if ( !v10 )
  {
    v6 = -1073741810;
    goto LABEL_43;
  }
  v12 = *(_DWORD *)(*(_DWORD *)(v10 + 176) + 20);
  v13 = *(_DWORD *)(v12 + 172);
  if ( v13 != 787 && v13 != 788 )
  {
    if ( v9 )
    {
      v6 = PnpQueryDeviceRelations(v10, v9, 0, &v25);
      if ( v6 < 0 )
      {
        v16 = 0;
        v25 = 0;
        goto LABEL_26;
      }
    }
    else
    {
      v14 = *(_DWORD **)(v12 + 4);
      v15 = 0;
      while ( v14 )
      {
        v14 = (_DWORD *)*v14;
        ++v15;
      }
      v16 = (unsigned int *)ExAllocatePoolWithTag(1, 4 * (v15 + 2), 538996816);
      v25 = v16;
      if ( !v16 )
      {
        v6 = -1073741670;
        goto LABEL_26;
      }
      *v16 = v15;
      v17 = *(_DWORD **)(v12 + 4);
      for ( i = 0; v17 && i < v15; ++i )
      {
        ObfReferenceObject(v17[4]);
        v19 = &v25[i];
        v19[1] = v17[4];
        v17 = (_DWORD *)*v17;
      }
    }
    v16 = v25;
LABEL_26:
    if ( v16 && *v16 )
    {
      v20 = 0;
      v7 = 2;
      if ( *v16 )
      {
        do
        {
          v21 = *(_DWORD *)(*(_DWORD *)(v16[v20 + 1] + 176) + 20);
          if ( v21 )
          {
            if ( v4 )
            {
              v22 = *(unsigned __int16 *)(v21 + 20);
              v5 = v26;
              if ( *v26 < v22 + v7 + 2 )
              {
                v6 = -1073741789;
                goto LABEL_43;
              }
              memmove((int)v4, *(_DWORD *)(v21 + 24), v22);
              v23 = &v4[*(unsigned __int16 *)(v21 + 20) >> 1];
              *v23 = 0;
              v4 = v23 + 1;
              v16 = v25;
            }
            v7 += *(unsigned __int16 *)(v21 + 20) + 2;
          }
          ObfDereferenceObject(v16[v20 + 1]);
          v16 = v25;
          ++v20;
        }
        while ( v20 < *v25 );
      }
      v5 = v26;
      if ( v4 )
        *v4 = 0;
    }
    else
    {
      v5 = v26;
    }
    goto LABEL_43;
  }
  v6 = -1073741810;
LABEL_43:
  PpDevNodeUnlockTree(0);
  if ( v6 < 0 )
    *v5 = 0;
  else
    *v5 = v7;
  if ( v25 )
    ExFreePoolWithTag((unsigned int)v25);
  if ( v11 )
    ObfDereferenceObject(v11);
  return v6;
}
