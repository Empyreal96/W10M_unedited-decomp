// PfpOpenHandleCreate 
 
int __fastcall PfpOpenHandleCreate(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v12; // r2
  int result; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r2
  _DWORD *v18; // [sp+10h] [bp-60h] BYREF
  int v19; // [sp+14h] [bp-5Ch]
  int v20; // [sp+18h] [bp-58h]
  int v21; // [sp+1Ch] [bp-54h]
  int v22; // [sp+20h] [bp-50h]
  int v23; // [sp+24h] [bp-4Ch]
  int v24; // [sp+28h] [bp-48h]
  int v25; // [sp+2Ch] [bp-44h]
  int v26; // [sp+30h] [bp-40h]
  int v27; // [sp+34h] [bp-3Ch]
  int v28; // [sp+38h] [bp-38h]
  int v29; // [sp+3Ch] [bp-34h]
  int v30; // [sp+40h] [bp-30h]
  int v31; // [sp+44h] [bp-2Ch]
  int v32; // [sp+48h] [bp-28h]
  int v33; // [sp+4Ch] [bp-24h]

  if ( (a2[10] & 4) != 0 )
    JUMPOUT(0x806D3E);
  v12 = (_DWORD *)a2[3];
  if ( v12 )
  {
    v16 = *(_DWORD *)(*v12 + 52);
    if ( v16 )
    {
      if ( *(_DWORD *)(v16 + 4) )
        return -1073741248;
    }
    if ( (*(_DWORD *)(*v12 + 56) & 4) != 0 )
    {
      v17 = v12[5];
      if ( *(_DWORD *)(v17 + 44) || (*(_DWORD *)(v17 + 40) & 4) != 0 )
        return -1073741248;
    }
  }
  v19 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v18 = a2 + 5;
  v20 = 24;
  v21 = a4;
  v22 = a3;
  v23 = 576;
  v24 = 0;
  v25 = 0;
  v26 = a5;
  v27 = a7;
  v28 = a6;
  if ( a8 )
    v19 = *(_DWORD *)(a8 + 4);
  result = (*(int (__fastcall **)(_DWORD **))dword_637348)(&v18);
  if ( result < 0 )
  {
    ++a2[13];
    if ( v32 == 2 )
    {
      if ( result != -1073741790 )
        a1[4] |= 1u;
    }
    else
    {
      result = sub_806CDC();
    }
  }
  else
  {
    a1[1] = v30;
    *a1 = v29;
    a1[2] = v31;
    a1[3] = v33;
    __dmb(0xBu);
    v14 = a2 + 12;
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 + 1, v14) );
    __dmb(0xBu);
    result = 0;
    a1[4] |= 4u;
  }
  return result;
}
