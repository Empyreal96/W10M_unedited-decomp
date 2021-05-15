// sub_548000 
 
void sub_548000()
{
  int *v0; // r5
  int *v1; // r7
  unsigned int v2; // r8
  int v3; // r3
  int v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r1
  int *v8; // r6
  unsigned int v9; // lr
  int *v10; // r2
  unsigned int v11; // r1
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned __int8 v15; // [sp+0h] [bp-28h] BYREF

  v3 = *((char *)v0 + 12);
  __dmb(0xBu);
  if ( !v3 )
    JUMPOUT(0x4C6DD0);
  MmLockLoadedModuleListShared(&v15);
  v4 = *v0;
  if ( *v0 == 1 )
    goto LABEL_10;
  v5 = v4 - 1;
  v6 = 1;
  if ( v4 - 1 < 1 )
    goto LABEL_10;
  while ( 1 )
  {
    v7 = (v5 + v6) >> 1;
    v8 = &v0[4 * v7 + 4];
    v9 = v8[1];
    if ( v2 >= v9 )
    {
      if ( v2 < v8[2] + v9 )
      {
        if ( v8 )
        {
          v12 = v8[1];
          v13 = v8[2];
          v14 = v8[3];
          *v1 = *v8;
          v1[1] = v12;
          v1[2] = v13;
          v1[3] = v14;
          goto LABEL_19;
        }
LABEL_10:
        if ( *((_BYTE *)v0 + 12) )
        {
          v10 = (int *)PsLoadedModuleList;
          if ( PsLoadedModuleList )
          {
            if ( (int *)PsLoadedModuleList != &PsLoadedModuleList )
            {
              while ( 1 )
              {
                v11 = v10[6];
                if ( v2 >= v11 && v2 < v10[8] + v11 )
                  break;
                v10 = (int *)*v10;
                if ( v10 == &PsLoadedModuleList )
                  goto LABEL_19;
              }
              *v1 = v10[2];
              v1[1] = v11;
              v1[2] = v10[8];
              v1[3] = v10[3];
            }
          }
        }
LABEL_19:
        MmUnlockLoadedModuleListShared(v15);
        JUMPOUT(0x4C6DDC);
      }
      v6 = v7 + 1;
    }
    else
    {
      if ( !v7 )
        goto LABEL_10;
      v5 = v7 - 1;
    }
    if ( v5 < v6 )
      goto LABEL_10;
  }
}
