// sub_7E7EB0 
 
void __fastcall sub_7E7EB0(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int a8, int a9)
{
  char v9; // cf
  unsigned int v10; // r4
  unsigned int v14; // r8
  int v15; // r6
  unsigned int v16; // r7
  unsigned __int16 *v17; // r5
  int v18; // r9
  unsigned int v19; // r8
  int v20; // r6
  unsigned int v21; // r7
  unsigned __int16 *v22; // r10
  int v23; // r9
  unsigned int v24; // [sp+0h] [bp+0h]
  unsigned int v25; // [sp+0h] [bp+0h]

  v14 = v10;
  v24 = v10;
  if ( v9 )
  {
LABEL_11:
    v19 = v10;
    v25 = v10;
    if ( v10 >= a7 )
LABEL_23:
      JUMPOUT(0x6F9ABC);
    v20 = a9 + 8 * v10;
    while ( 1 )
    {
      v21 = v10;
      if ( v10 < a8 )
      {
        v22 = *(unsigned __int16 **)v20;
        v23 = a6 + 8 * v10;
        do
        {
          if ( RtlEqualSid(v22, *(unsigned __int16 **)v23)
            && ((*(_DWORD *)(v20 + 4) ^ *(_DWORD *)(v23 + 4)) & 0x14) == 0 )
          {
            break;
          }
          ++v21;
          v23 += 8;
        }
        while ( v21 < a8 );
        v19 = v25;
      }
      if ( v21 == a8 )
        break;
      ++v19;
      v20 += 8;
      v25 = v19;
      if ( v19 >= a7 )
        goto LABEL_23;
    }
  }
  else
  {
    v15 = a4 + 8 * v10;
    while ( 1 )
    {
      v16 = v10;
      if ( v10 < a7 )
      {
        v17 = *(unsigned __int16 **)v15;
        v18 = a9 + 8 * v10;
        do
        {
          if ( RtlEqualSid(v17, *(unsigned __int16 **)v18)
            && ((*(_DWORD *)(v18 + 4) ^ *(_DWORD *)(v15 + 4)) & 0x14) == 0 )
          {
            break;
          }
          ++v16;
          v18 += 8;
        }
        while ( v16 < a7 );
        v14 = v24;
      }
      if ( v16 == a7 )
        break;
      ++v14;
      v15 += 8;
      v24 = v14;
      if ( v14 >= a8 )
        goto LABEL_11;
    }
  }
  JUMPOUT(0x6F9AC4);
}
