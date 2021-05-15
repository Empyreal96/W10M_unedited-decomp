// EmpEvaluateTargetRule 
 
int __fastcall EmpEvaluateTargetRule(_DWORD *a1, int a2, int a3)
{
  __int64 v3; // kr00_8
  int v4; // r6
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r1
  unsigned int v8; // r0
  int v9; // r10
  unsigned int v10; // r9
  int *v11; // r0
  int v12; // lr
  int *v13; // r1
  unsigned int v14; // r10
  int v15; // r7
  int *v16; // r1
  int v17; // r0
  _DWORD *v18; // r2
  int v19; // t1
  _DWORD *v20; // r2
  int v21; // r0
  int v22; // t1
  int v23; // r0
  int *v25; // [sp+18h] [bp-38h]
  int *v26; // [sp+1Ch] [bp-34h]
  unsigned int v27; // [sp+20h] [bp-30h]
  int v28; // [sp+24h] [bp-2Ch]

  v3 = *(_QWORD *)(a1[1] + 32);
  v4 = 0;
  v5 = 0;
  v6 = 1;
  v28 = a1[1];
  v25 = (int *)a1[2];
  if ( !v3 )
    return sub_51F87C();
  v7 = a1[3];
  v8 = HIDWORD(v3) + v3;
  if ( !(HIDWORD(v3) + (_DWORD)v3) )
    __brkdiv0();
  v9 = v7 / v8;
  v27 = v7 / v8;
  if ( !(_DWORD)v3 || (v4 = ExAllocatePoolWithTag(1, 4 * v3, 1986350405)) != 0 )
  {
    if ( !HIDWORD(v3) || (v5 = ExAllocatePoolWithTag(1, 4 * HIDWORD(v3), 1986350405)) != 0 )
    {
      v10 = 0;
      if ( v9 )
      {
        v11 = v25;
        v12 = v28;
        v13 = &v25[v3];
        v26 = v13;
        v14 = HIDWORD(v3) + v3;
        do
        {
          if ( (_DWORD)v3 )
          {
            v15 = EmpStringTable;
            v16 = v11;
            v17 = v3;
            v18 = (_DWORD *)v4;
            do
            {
              v19 = *v16++;
              --v17;
              *v18++ = *(_DWORD *)(v15 + 4 * v19);
            }
            while ( v17 );
            v13 = v26;
          }
          if ( (unsigned int)v3 < v14 )
          {
            v20 = (_DWORD *)v5;
            v21 = HIDWORD(v3);
            do
            {
              v22 = *v13++;
              --v21;
              *v20++ = v22;
            }
            while ( v21 );
          }
          v23 = EmpEvaluateNodeLink(*(_DWORD *)(v12 + 64), v4, v3, v5, HIDWORD(v3), a2, a3, 0, 0);
          v6 = v23;
          if ( v23 == 2 )
            break;
          if ( v23 == 1 )
            break;
          v12 = v28;
          ++v10;
          v11 = &v25[v14];
          v13 = &v26[v14];
          v25 = v11;
          v26 = v13;
        }
        while ( v10 < v27 );
      }
    }
    if ( v4 )
      ExFreePoolWithTag(v4, 1986350405);
    if ( v5 )
      ExFreePoolWithTag(v5, 1986350405);
  }
  return v6;
}
