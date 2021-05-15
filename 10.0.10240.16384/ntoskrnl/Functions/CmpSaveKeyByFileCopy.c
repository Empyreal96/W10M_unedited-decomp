// CmpSaveKeyByFileCopy 
 
int __fastcall CmpSaveKeyByFileCopy(int *a1, int a2)
{
  _DWORD *v4; // r7
  int v5; // r5
  unsigned int v6; // r9
  unsigned int v7; // r6
  unsigned int v8; // r8
  int v9; // r3
  unsigned int v11; // [sp+8h] [bp-30h] BYREF
  unsigned int v12; // [sp+Ch] [bp-2Ch]
  unsigned int v13; // [sp+10h] [bp-28h] BYREF
  _DWORD *v14; // [sp+14h] [bp-24h]
  unsigned int v15; // [sp+18h] [bp-20h]

  v4 = (_DWORD *)ExAllocatePoolWithQuotaTag(0xDu, 0x10000u, 538987843);
  if ( !v4 )
    return -1073741670;
  CmpBecomeActiveFlusherAndReconciler(a1);
  if ( (a1[828] & 8) != 0 )
  {
    v5 = -1073741670;
  }
  else
  {
    v11 = 0;
    v5 = -1073741491;
    a1[446] = a2;
    if ( CmpFileRead((int)a1, 0, (int *)&v11, (int)v4, 0x1000u) )
    {
      v6 = v4[10];
      ++v4[1];
      v11 = 0;
      v13 = 0;
      v14 = v4;
      v15 = 4096;
      if ( CmpFileWrite((int)a1, 2, (int)&v13, 1u, &v11, 0) )
      {
        v7 = 0;
        if ( v6 )
        {
          while ( 1 )
          {
            v8 = v6 - v7;
            if ( v6 - v7 > 0x10000 )
              v8 = 0x10000;
            v11 = v7 + 4096;
            v12 = v7 + 4096;
            if ( !CmpFileRead((int)a1, 0, (int *)&v11, (int)v4, v8) )
              break;
            v11 = v12;
            v13 = v12;
            v14 = v4;
            v15 = v8;
            if ( !CmpFileWrite((int)a1, 2, (int)&v13, 1u, &v11, 0) )
              break;
            v7 += v8;
            if ( v7 >= v6 )
              goto LABEL_13;
          }
        }
        else
        {
LABEL_13:
          if ( CmpFileFlush((int)a1, 2) )
            v5 = 0;
          v11 = 0;
          if ( CmpFileRead((int)a1, 0, (int *)&v11, (int)v4, 0x1000u) )
          {
            ++v4[1];
            v9 = v4[2];
            v14 = v4;
            v15 = 4096;
            v4[2] = v9 + 1;
            v11 = 0;
            v13 = 0;
            if ( CmpFileWrite((int)a1, 2, (int)&v13, 1u, &v11, 0) )
            {
              if ( CmpFileFlush((int)a1, 2) )
                v5 = 0;
            }
          }
        }
      }
    }
  }
  a1[446] = 0;
  CmpFinishBeingActiveFlusherAndReconciler(a1);
  ExFreePoolWithTag((unsigned int)v4);
  return v5;
}
