// EtwpPoolRunDown 
 
int __fastcall EtwpPoolRunDown(int a1, int a2)
{
  int v2; // r6
  unsigned int *v3; // r4
  int v4; // r9
  unsigned int v5; // r5
  unsigned int *v6; // r0
  int v7; // r3
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r7
  int v11; // r10
  int v12; // r3
  int v13; // r6
  unsigned int v14; // r5
  unsigned int *v15; // r0
  int v16; // r0
  unsigned int v17; // r5
  int v18; // r7
  int v19; // r10
  int v20; // r3
  int v21; // r0
  int v22; // r7
  int v23; // r5
  unsigned int *v24; // r0
  int v25; // r0
  unsigned int v26; // r5
  int v27; // r8
  int v28; // r9
  int v29; // r3
  int v30; // r7
  unsigned int v31; // r5
  unsigned int *v32; // r0
  int v33; // r2
  int v34; // r3
  int v35; // r0
  unsigned int v36; // r5
  int v37; // r8
  int v38; // r9
  int v39; // r3
  int result; // r0
  int v41; // r2
  int v42; // r3
  int v43; // r6
  unsigned int v44; // [sp+8h] [bp-80h] BYREF
  unsigned int i; // [sp+Ch] [bp-7Ch] BYREF
  int v46; // [sp+10h] [bp-78h]
  int v47; // [sp+14h] [bp-74h] BYREF
  int v48; // [sp+18h] [bp-70h]
  int v49; // [sp+1Ch] [bp-6Ch] BYREF
  char v50[24]; // [sp+20h] [bp-68h] BYREF
  int v51[4]; // [sp+38h] [bp-50h] BYREF
  int *v52; // [sp+48h] [bp-40h]
  int v53; // [sp+4Ch] [bp-3Ch]
  int v54; // [sp+50h] [bp-38h]
  int v55; // [sp+54h] [bp-34h]
  int v56; // [sp+58h] [bp-30h]
  int v57; // [sp+5Ch] [bp-2Ch]
  int v58; // [sp+60h] [bp-28h]
  int v59; // [sp+64h] [bp-24h]

  v51[0] = (int)&v44;
  v51[1] = 0;
  v51[2] = 4;
  v51[3] = 0;
  v2 = 3625;
  v3 = 0;
  v4 = a2;
  v48 = a2;
  v46 = a1;
  if ( a2 )
    v2 = 3624;
  v5 = 32;
  for ( i = 32; ; v5 = i )
  {
    if ( v3 )
      ExFreePoolWithTag((unsigned int)v3);
    v6 = (unsigned int *)ExAllocatePoolWithTag(1, v5, 1953985605);
    v3 = v6;
    if ( !v6 )
      break;
    v8 = ExGetPoolTagInfo(v6, v5, &i, v7);
    if ( v8 != -1073741820 )
    {
      if ( v8 >= 0 )
      {
        v9 = *v3;
        v10 = (int)(v3 + 1);
        if ( *v3 )
        {
          v11 = v46;
          do
          {
            if ( v9 <= 0x64 )
            {
              v12 = v9;
              v44 = v9;
            }
            else
            {
              v12 = 100;
              v44 = 100;
            }
            v54 = 28 * v12;
            v55 = 0;
            v52 = (int *)v10;
            v53 = 0;
            EtwpLogKernelEvent(v51, v11, 2, v2, 4200450);
            v9 -= v44;
            v10 += 28 * v44;
          }
          while ( v9 );
        }
      }
      break;
    }
  }
  v13 = 3627;
  if ( v4 )
    v13 = 3626;
  v14 = 16;
  for ( i = 16; ; v14 = i )
  {
    if ( v3 )
      ExFreePoolWithTag((unsigned int)v3);
    v15 = (unsigned int *)ExAllocatePoolWithTag(1, v14, 1953985605);
    v3 = v15;
    if ( !v15 )
      break;
    v16 = ExGetBigPoolInfo(v15, v14, 1, &i);
    if ( v16 != -1073741820 )
    {
      if ( v16 >= 0 )
      {
        v17 = *v3;
        v18 = (int)(v3 + 1);
        if ( *v3 )
        {
          v19 = v46;
          do
          {
            if ( v17 <= 0x64 )
            {
              v20 = v17;
              v44 = v17;
            }
            else
            {
              v20 = 100;
              v44 = 100;
            }
            v54 = 12 * v20;
            v55 = 0;
            v52 = (int *)v18;
            v53 = 0;
            EtwpLogKernelEvent(v51, v19, 2, v13, 4200450);
            v17 -= v44;
            v18 += 12 * v44;
          }
          while ( v17 );
        }
      }
      break;
    }
  }
  while ( 1 )
  {
    result = MmGetNextSession();
    v43 = result;
    if ( !result )
      break;
    if ( MmAttachSession(result, (int)v50, v41, v42) >= 0 )
    {
      v21 = MmGetSessionId(v43);
      v22 = 3629;
      if ( v4 )
        v22 = 3628;
      v47 = v21;
      v23 = 2800;
      while ( 1 )
      {
        if ( v3 )
          ExFreePoolWithTag((unsigned int)v3);
        v24 = (unsigned int *)ExAllocatePoolWithTag(1, v23, 1953985605);
        v3 = v24;
        if ( !v24 )
          break;
        v25 = ExGetSessionPoolTagInfo(v24, v23, (int)&v44, (int)&v49);
        v23 = 28 * v49;
        if ( v25 != -1073741820 )
        {
          if ( v25 >= 0 )
          {
            v52 = &v47;
            v53 = 0;
            v26 = v44;
            v54 = 4;
            v55 = 0;
            v27 = (int)v3;
            if ( v44 )
            {
              v28 = v46;
              do
              {
                if ( v26 <= 0x64 )
                {
                  v29 = v26;
                  v44 = v26;
                }
                else
                {
                  v29 = 100;
                  v44 = 100;
                }
                v58 = 28 * v29;
                v59 = 0;
                v56 = v27;
                v57 = 0;
                EtwpLogKernelEvent(v51, v28, 3, v22, 4200450);
                v26 -= v44;
                v27 += 28 * v44;
              }
              while ( v26 );
              v4 = v48;
            }
          }
          break;
        }
      }
      v30 = 3631;
      if ( v4 )
        v30 = 3630;
      v31 = 24;
      for ( i = 24; ; v31 = i )
      {
        if ( v3 )
          ExFreePoolWithTag((unsigned int)v3);
        v32 = (unsigned int *)ExAllocatePoolWithTag(1, v31, 1953985605);
        v3 = v32;
        if ( !v32 )
          break;
        v35 = ExGetBigPoolInfo(v32, v31, 0, &i);
        if ( v35 != -1073741820 )
        {
          if ( v35 >= 0 )
          {
            v52 = &v47;
            v53 = 0;
            v54 = 4;
            v34 = 0;
            v55 = 0;
            v36 = v3[2];
            v37 = (int)(v3 + 3);
            if ( v36 )
            {
              v38 = v46;
              do
              {
                if ( v36 <= 0x64 )
                {
                  v39 = v36;
                  v44 = v36;
                }
                else
                {
                  v39 = 100;
                  v44 = 100;
                }
                v58 = 12 * v39;
                v59 = 0;
                v56 = v37;
                v57 = 0;
                EtwpLogKernelEvent(v51, v38, 3, v30, 4200450);
                v36 -= v44;
                v34 = 3 * v44;
                v37 += 12 * v44;
              }
              while ( v36 );
              v4 = v48;
            }
          }
          break;
        }
      }
      MmDetachSession(v43, (int)v50, v33, v34);
    }
  }
  if ( v3 )
    result = ExFreePoolWithTag((unsigned int)v3);
  return result;
}
