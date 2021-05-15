// CmpConstructName 
 
int __fastcall CmpConstructName(int a1)
{
  int v1; // r4
  unsigned int v2; // r6
  int v3; // r8
  int v4; // r2
  int v5; // r1
  int v6; // r3
  unsigned int v7; // r6
  int v9; // r0
  unsigned int v10; // r7
  int v11; // r5
  unsigned int v12; // r3
  int v13; // r5
  int v14; // r2
  int v15; // r3
  _WORD *v16; // r1
  _WORD *v17; // r1
  __int16 *v18; // r2
  unsigned int v19; // r0
  __int16 v20; // t1
  _WORD *v21; // r0
  _WORD *v22; // r0
  unsigned int v23; // r1
  __int16 v24; // t1
  int v25[8]; // [sp+0h] [bp-20h] BYREF

  v1 = a1;
  v2 = 0;
  v25[0] = -1;
  v3 = 0;
  v4 = a1;
  if ( a1 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 44);
      v6 = *(unsigned __int16 *)(v5 + 12);
      if ( (*(_DWORD *)v5 & 1) != 0 )
        v7 = v2 + 2 * v6;
      else
        v7 = v2 + v6;
      v4 = *(_DWORD *)(v4 + 40);
      v2 = v7 + 2;
    }
    while ( v4 );
    if ( v2 > 0xFFFF )
      return sub_80478C();
  }
  v9 = ExAllocatePoolWithTag(1, v2 + 8, 1649298755);
  v10 = v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 4) = v9 + 8;
    *(_WORD *)v9 = v2;
    *(_WORD *)(v9 + 2) = v2;
    if ( v1 )
    {
      while ( 1 )
      {
        v11 = *(_DWORD *)(v1 + 20);
        if ( !v11 )
          break;
        v12 = *(_DWORD *)(v1 + 4);
        if ( (v12 & 0x10) != 0 )
          break;
        if ( ((v12 >> 17) & 1) != 0 )
          goto LABEL_28;
        if ( *(_DWORD *)(v1 + 24) == -1 )
          break;
        if ( v3 )
        {
LABEL_28:
          v3 = 1;
          v13 = 0;
        }
        else
        {
          v13 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v11 + 4))(
                  *(_DWORD *)(v1 + 20),
                  *(_DWORD *)(v1 + 24),
                  v25);
          if ( !v13 )
            break;
        }
        v14 = *(_DWORD *)(v1 + 44);
        v15 = *(unsigned __int16 *)(v14 + 12);
        if ( (*(_DWORD *)v14 & 1) != 0 )
        {
          v2 = v2 - 2 * v15 - 2;
          v16 = (_WORD *)(*(_DWORD *)(v10 + 4) + 2 * (v2 >> 1));
          *v16 = 92;
          v17 = v16 + 1;
          if ( (*(_WORD *)(v1 + 106) & 6) != 0 || !v13 )
            v18 = (__int16 *)(*(_DWORD *)(v1 + 44) + 14);
          else
            v18 = (__int16 *)(v13 + 76);
          if ( *(_WORD *)(*(_DWORD *)(v1 + 44) + 12) )
          {
            LOWORD(v19) = 0;
            do
            {
              v20 = *(unsigned __int8 *)v18;
              v18 = (__int16 *)((char *)v18 + 1);
              *v17++ = v20;
              v19 = (unsigned __int16)(v19 + 1);
            }
            while ( v19 < *(unsigned __int16 *)(*(_DWORD *)(v1 + 44) + 12) );
          }
        }
        else
        {
          v2 = v2 - v15 - 2;
          v21 = (_WORD *)(*(_DWORD *)(v10 + 4) + 2 * (v2 >> 1));
          *v21 = 92;
          v22 = v21 + 1;
          if ( (*(_WORD *)(v1 + 106) & 6) != 0 || !v13 )
            v18 = (__int16 *)(*(_DWORD *)(v1 + 44) + 14);
          else
            v18 = (__int16 *)(v13 + 76);
          if ( *(_WORD *)(*(_DWORD *)(v1 + 44) + 12) )
          {
            LOWORD(v23) = 0;
            do
            {
              v24 = *v18++;
              *v22++ = v24;
              v23 = (unsigned __int16)(v23 + 2);
            }
            while ( v23 < *(unsigned __int16 *)(*(_DWORD *)(v1 + 44) + 12) );
          }
        }
        if ( v13 )
          (*(void (__fastcall **)(_DWORD, int *, __int16 *))(*(_DWORD *)(v1 + 20) + 8))(*(_DWORD *)(v1 + 20), v25, v18);
        v1 = *(_DWORD *)(v1 + 40);
        if ( !v1 )
          return v10;
      }
      ExFreePoolWithTag(v10);
      v10 = 0;
    }
  }
  return v10;
}
