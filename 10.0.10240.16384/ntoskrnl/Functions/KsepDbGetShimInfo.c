// KsepDbGetShimInfo 
 
int __fastcall KsepDbGetShimInfo(_DWORD *a1, unsigned int a2)
{
  int v3; // r9
  int v5; // r7
  int v6; // r5
  int v7; // r0
  _DWORD *v8; // r10
  char *v9; // r2
  int v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r2
  int v15; // r3
  int v16; // r4
  int v17; // r1
  int v18; // r0
  int v19; // r3
  int v20; // r0
  int v21; // r0
  int v22; // r0
  unsigned int v23; // lr
  int v24; // r2
  int v25; // r3
  int v26; // r4
  int v28; // [sp+10h] [bp-90h] BYREF
  int v29; // [sp+14h] [bp-8Ch] BYREF
  int v30; // [sp+18h] [bp-88h] BYREF
  int v31; // [sp+1Ch] [bp-84h]
  int v32; // [sp+20h] [bp-80h] BYREF
  int v33; // [sp+28h] [bp-78h] BYREF
  int v34; // [sp+2Ch] [bp-74h]
  int v35; // [sp+30h] [bp-70h]
  int v36; // [sp+34h] [bp-6Ch]
  char v37[40]; // [sp+38h] [bp-68h] BYREF
  int v38[4]; // [sp+60h] [bp-40h] BYREF
  int v39[12]; // [sp+70h] [bp-30h] BYREF

  v28 = 0;
  v29 = 0;
  v38[0] = 0;
  v38[1] = 0;
  v38[2] = 0;
  v38[3] = 0;
  v3 = 0;
  v5 = KseShimDatabaseOpen(&v29);
  v6 = v29;
  if ( v5 >= 0 )
  {
    v7 = KsepPoolAllocatePaged(52 * a2);
    v5 = -1073741275;
    v31 = 0;
    v3 = v7;
    if ( a2 )
    {
      v8 = (_DWORD *)v7;
      v9 = (char *)a1 - v7;
      while ( 1 )
      {
        v32 = 0;
        v10 = *(_DWORD *)(v6 + 4);
        v11 = SdbFindFirstStringIndexedTag(v10, 28709, 24577, *(_DWORD *)((char *)v8 + (_DWORD)v9 + 20), (int)v37);
        v12 = SdbTagIDToTagRef(v6, v10, v11, &v32) ? v32 : 0;
        if ( !v12 )
          break;
        if ( SdbTagRefToTagID(v6, v12, &v28, &v30) )
        {
          v13 = SdbFindFirstTag(v28, v30, 36880);
          if ( !v13 )
            break;
          SdbReadGUIDTag(&v33, v28, v13, v38[0]);
          v39[0] = v33;
          v39[1] = v34;
          v39[2] = v35;
          v39[3] = v36;
          if ( !memcmp((unsigned int)v39, (unsigned int)v38, 16) )
            break;
          v14 = v34;
          v15 = v35;
          v16 = v36;
          v17 = v30;
          *v8 = v33;
          v8[1] = v14;
          v8[2] = v15;
          v8[3] = v16;
          v18 = SdbFindFirstTag(v28, v17, 24579);
          if ( !v18 )
            break;
          v5 = KsepDbGetSdbString(v28, v18, (int)(v8 + 6), v19);
          if ( v5 < 0 )
            break;
          v20 = SdbFindFirstTag(v28, v30, 16407);
          if ( !v20 )
            break;
          v21 = SdbReadDWORDTag(v28, v20, 0);
          v6 = v29;
          v8[10] = v21;
        }
        v8 += 13;
        v9 = (char *)a1 - v3;
        if ( ++v31 >= a2 )
          goto LABEL_16;
      }
    }
    else
    {
LABEL_16:
      v5 = 0;
      if ( a2 )
      {
        v22 = v3 - (_DWORD)a1;
        v23 = a2;
        do
        {
          a1[10] = *(_DWORD *)((char *)a1 + v22 + 40);
          a1[6] = *(_DWORD *)((char *)a1 + v22 + 24);
          a1[7] = *(_DWORD *)((char *)a1 + v22 + 28);
          v24 = *(_DWORD *)((char *)a1 + v22 + 4);
          v25 = *(_DWORD *)((char *)a1 + v22 + 8);
          v26 = *(_DWORD *)((char *)a1 + v22 + 12);
          *a1 = *(_DWORD *)((char *)a1 + v22);
          a1[1] = v24;
          a1[2] = v25;
          a1[3] = v26;
          a1 += 13;
          --v23;
        }
        while ( v23 );
      }
    }
  }
  if ( v29 )
    KseShimDatabaseClose(v29);
  if ( v5 >= 0 )
    KsepPoolFreePaged(v3);
  else
    KsepDbFreeDriverShims(v3);
  return v5;
}
