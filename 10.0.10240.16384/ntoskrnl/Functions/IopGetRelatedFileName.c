// IopGetRelatedFileName 
 
int __fastcall IopGetRelatedFileName(int a1, int a2, int a3, _WORD *a4)
{
  unsigned int *v4; // r6
  unsigned __int16 *v5; // r5
  int v6; // r4
  unsigned int v7; // r7
  unsigned int v9; // r10
  unsigned __int16 *v10; // r0
  int v11; // r0
  int v12; // r4
  int v13; // r10
  unsigned int *v14; // r0
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r0
  int v19; // [sp+8h] [bp-30h] BYREF
  int v20; // [sp+Ch] [bp-2Ch]
  int v21; // [sp+10h] [bp-28h]
  _WORD *v22; // [sp+14h] [bp-24h]
  int v23; // [sp+18h] [bp-20h]

  v22 = a4;
  v23 = a3;
  v19 = 0;
  v4 = 0;
  v5 = 0;
  v6 = a1;
  v7 = 256;
  v20 = -2147483643;
  v21 = a1;
  v9 = 256;
  while ( 1 )
  {
    if ( v5 )
    {
      ExFreePoolWithTag((unsigned int)v5);
      v5 = 0;
    }
    if ( v9 >= 0xFFFF )
    {
      v12 = -1073741562;
      goto LABEL_28;
    }
    v10 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v9, 1665560393);
    v5 = v10;
    if ( !v10 )
      return -1073741670;
    memset(v10, 0, v9);
    v11 = ObQueryNameStringMode(*(_DWORD *)(v6 + 4), (int)v5, v9, &v19, 0);
    v12 = v11;
    v9 = v19 + 8;
    if ( v22 )
      *v22 = *v5;
    if ( v11 != v20 )
      break;
    v6 = v21;
  }
  if ( v11 >= 0 )
  {
    v13 = v20;
    do
    {
      if ( v4 )
      {
        ExFreePoolWithTag((unsigned int)v4);
        v4 = 0;
      }
      if ( v7 >= 0xFFFF )
        goto LABEL_23;
      v14 = (unsigned int *)ExAllocatePoolWithTag(1, v7, 1665560393);
      v4 = v14;
      if ( !v14 )
      {
        v12 = -1073741670;
        goto LABEL_28;
      }
      memset(v14, 0, v7);
      v15 = IopGetFileInformation(*(_DWORD **)(v21 + 32), v7, 9, (int)v4, &v19);
      v12 = v15;
      v7 = *v4 + 8;
    }
    while ( v15 == v13 );
    if ( v15 < 0 )
      goto LABEL_24;
    v16 = *v4 + *v5 + v23;
    if ( v16 >= 0xFFFF )
    {
LABEL_23:
      v12 = -1073741562;
      goto LABEL_24;
    }
    *(_WORD *)a2 = *(_WORD *)v4 + *v5;
    *(_WORD *)(a2 + 2) = v16;
    v17 = ExAllocatePoolWithTag(1, v16, 1665560393);
    *(_DWORD *)(a2 + 4) = v17;
    if ( v17 )
    {
      memmove(v17, *((_DWORD *)v5 + 1), *v5);
      memmove(*v5 + *(_DWORD *)(a2 + 4), (int)(v4 + 1), *v4);
    }
    else
    {
      v12 = -1073741670;
    }
LABEL_24:
    if ( v4 )
      ExFreePoolWithTag((unsigned int)v4);
  }
LABEL_28:
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  return v12;
}
