// MiPhysicalPoolCheck 
 
int __fastcall MiPhysicalPoolCheck(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, int a7, int a8)
{
  int v10; // r4
  unsigned int v11; // r10
  int result; // r0
  unsigned int v13; // r7
  int v14; // r5
  unsigned int v15; // r1
  unsigned int v16; // r9
  int i; // r6
  unsigned int v18; // r3
  unsigned int v19; // r2
  _DWORD *v20; // r1
  unsigned int v21; // r4
  unsigned int v22; // r6
  unsigned int v23; // r2
  unsigned int v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // [sp+0h] [bp-30h]

  v10 = a1 + a2;
  v11 = 0;
  result = -1;
  v13 = 0;
  v14 = -1;
  v15 = *(_DWORD *)(dword_6337E8 + 176 * a8 + 136) + (v10 << 12);
  v26 = v15;
  if ( a3 )
  {
    v16 = a6;
    for ( i = MmPfnDatabase; ; i = MmPfnDatabase )
    {
      if ( v14 == -1 )
        v18 = a3 - v13;
      else
        v18 = a3 - v14;
      if ( v18 < a4 )
        return result;
      v19 = ((v15 >> 10) & 0x3FFFFC) - 0x40000000;
      v20 = (_DWORD *)(((v15 >> 20) & 0xFFC) - 1070596096);
      v21 = (4096 - (v19 & 0xFFF)) >> 2;
      if ( v21 + v13 > a3 )
        v21 = a3 - v13;
      v22 = i + 24 * (((v19 >> 2) & 0x3FF) + (*v20 >> 12));
      if ( *(_DWORD *)(v22 + 20) >> 28 != a8 )
        return sub_5546E0();
      if ( v14 == -1 )
      {
        v23 = (int)(v22 - MmPfnDatabase) / 24;
        if ( v23 > a5 )
          goto LABEL_15;
        if ( v23 < v16 )
          JUMPOUT(0x5546E4);
        if ( v23 + a4 <= v23 )
          goto LABEL_15;
        v24 = v23 + a4 - 1;
        if ( v24 > a5 )
          goto LABEL_15;
        if ( a7 )
        {
          v16 = a6;
          if ( ((v24 ^ v23) & ~(a7 - 1)) != 0 )
          {
            v25 = (v23 + a7 - 1) & ~(a7 - 1);
            if ( v23 + v21 > v25 )
              v21 = v25 - v23;
            goto LABEL_15;
          }
        }
        v14 = v13;
      }
      else if ( v22 != v11 + 24 )
      {
        JUMPOUT(0x5546F4);
      }
      v11 = v22;
      if ( v14 != -1 && v13 - v14 + 1 >= a4 )
        return v14 + a1;
      v21 = 1;
LABEL_15:
      v13 += v21;
      v15 = v26 + (v21 << 12);
      v26 = v15;
      if ( v13 >= a3 )
        return result;
    }
  }
  return result;
}
