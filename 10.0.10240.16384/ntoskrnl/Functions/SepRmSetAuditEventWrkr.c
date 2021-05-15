// SepRmSetAuditEventWrkr 
 
int __fastcall SepRmSetAuditEventWrkr(int a1, int a2)
{
  int v2; // r8
  int v3; // r9
  int result; // r0
  unsigned int v5; // r2
  __int16 v6; // r10
  unsigned int v7; // r7
  int v8; // r5
  int v9; // lr
  unsigned int v10; // r6
  __int16 *v11; // r0
  char *v12; // r4
  __int16 v13; // t1
  int v14; // r3
  int v15; // r3
  unsigned int v16; // [sp+0h] [bp-30h]
  __int16 v17; // [sp+4h] [bp-2Ch]
  _BYTE *v18; // [sp+8h] [bp-28h]
  _BYTE *v19; // [sp+Ch] [bp-24h]
  int v20; // [sp+10h] [bp-20h]

  v2 = a1 + 28;
  *(_DWORD *)(a2 + 24) = 0;
  v20 = a1 + 28;
  v3 = 0;
  result = PsIsCurrentThreadInServerSilo();
  if ( !result )
  {
    v5 = 0;
    v18 = &SeAuditingState[-v2];
    v19 = &SeAuditingState[-v2];
    v16 = 0;
    v17 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = (unsigned __int16)AdtpPerCategoryCount[v5];
      v8 = 0;
      v9 = 0;
      SeAuditingStateByCategory[v5] = 0;
      if ( !v7 )
        goto LABEL_11;
      LOWORD(v10) = 0;
      v11 = (__int16 *)(v2 + 2 * v3);
      do
      {
        v12 = (char *)v11 + (_DWORD)v19;
        *((_BYTE *)v11 + (_DWORD)v19 + 1) = 0;
        *((_BYTE *)v11 + (_DWORD)v18) = 0;
        if ( (*v11 & 1) != 0 )
        {
          v8 = (unsigned __int16)(v8 + 1);
          *((_BYTE *)v11 + (_DWORD)v18) = 1;
        }
        v13 = *v11++;
        if ( (v13 & 2) != 0 )
        {
          v9 = (unsigned __int16)(v9 + 1);
          v12[1] = 1;
        }
        v10 = (unsigned __int16)(v10 + 1);
        ++v3;
      }
      while ( v10 < v7 );
      v5 = v16;
      v6 = v17;
      v2 = v20;
      if ( v8 )
      {
        if ( v8 == v7 )
          return sub_816BF4();
        v14 = 2;
        result = 2;
      }
      else
      {
LABEL_11:
        v14 = 4;
        result = 4;
      }
      SeAuditingStateByCategory[v5] = result;
      if ( v9 )
      {
        if ( v9 == v7 )
          v15 = v14 | 0x10;
        else
          v15 = v14 | 0x20;
      }
      else
      {
        v15 = v14 | 0x40;
      }
      SeAuditingStateByCategory[v5] = v15;
      v5 = (unsigned __int16)(v6 + 1);
      v16 = v5;
      v17 = ++v6;
      if ( v5 >= 9 )
      {
        SepRmAuditingEnabled = 1;
        return result;
      }
    }
  }
  return result;
}
