// IopTrackLink 
 
int __fastcall IopTrackLink(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, char a6)
{
  unsigned int v6; // lr
  _DWORD *v8; // r6
  int *v9; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r9
  int v15; // r0
  int v16; // r0
  int v17; // r8
  int v18; // r0
  int *v19; // r1
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // r0
  int v24; // r0
  int v25; // r0
  int v27; // [sp+8h] [bp-288h]
  unsigned int v29; // [sp+10h] [bp-280h]
  int v31; // [sp+1Ch] [bp-274h]
  int v32; // [sp+20h] [bp-270h]
  _DWORD *v33; // [sp+24h] [bp-26Ch] BYREF
  int v34; // [sp+28h] [bp-268h]
  int v35; // [sp+2Ch] [bp-264h]
  _BYTE v36[16]; // [sp+30h] [bp-260h] BYREF
  char v37; // [sp+40h] [bp-250h]
  int v38; // [sp+70h] [bp-220h] BYREF
  _BYTE v39[20]; // [sp+74h] [bp-21Ch] BYREF
  _BYTE v40[16]; // [sp+88h] [bp-208h] BYREF
  char v41; // [sp+98h] [bp-1F8h]
  int v42[8]; // [sp+A8h] [bp-1E8h] BYREF
  int v43; // [sp+C8h] [bp-1C8h] BYREF
  _BYTE v44[20]; // [sp+CCh] [bp-1C4h] BYREF
  _BYTE v45[16]; // [sp+E0h] [bp-1B0h] BYREF
  _BYTE v46[48]; // [sp+F0h] [bp-1A0h] BYREF
  _BYTE v47[16]; // [sp+120h] [bp-170h] BYREF
  int v48; // [sp+130h] [bp-160h] BYREF
  _DWORD _160[82]; // [sp+160h] [bp-130h] BYREF

  _160[78] = a1;
  _160[79] = a2;
  _160[80] = a3;
  v6 = a4;
  _160[81] = a4;
  v35 = a3;
  v33 = (_DWORD *)a2;
  v34 = a5;
  v8 = 0;
  v31 = 0;
  if ( a6 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v10 = 40;
      else
        v10 = 32;
      v9 = (int *)ExAllocatePoolWithTagPriority(1, v6, 538996553, v10);
      if ( !v9 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v9 = (int *)ExAllocatePoolWithQuotaTag(1u, a4, 538996553);
    }
    v29 = (unsigned int)v9;
    memmove((int)v9, v35, a4);
    v6 = a4;
  }
  else
  {
    v9 = (int *)a3;
    v29 = a3;
  }
  v11 = *v9;
  if ( !*v9 && a6 == 1 )
  {
LABEL_13:
    ExFreePoolWithTag((unsigned int)v9);
    return -1073741811;
  }
  if ( v6 >= 8 )
  {
    v13 = v9[1];
    if ( v6 - 8 < v13 )
    {
      if ( !a6 )
        return -1073741811;
      goto LABEL_13;
    }
    if ( v13 + 36 > 0x100 )
    {
      if ( a6 )
        ExFreePoolWithTag((unsigned int)v9);
      return -2147483643;
    }
    if ( v11 )
    {
      v12 = ObReferenceObjectByHandle(v11, 2, IoFileObjectType, a6, &v33);
      v32 = v12;
      v8 = v33;
      v31 = (int)v33;
      if ( v12 < 0 )
      {
        if ( a6 )
        {
          ExFreePoolWithTag((unsigned int)v9);
          v12 = v32;
        }
        return v12;
      }
    }
    if ( (*(_DWORD *)(a1[1] + 32) & 0x10) != 0 )
    {
      v24 = IopGetSetObjectId(a1, (int)v40, 64, 589980);
      v27 = v24;
      if ( v24 == -1073741772 )
        goto LABEL_31;
      if ( v24 < 0 )
        goto LABEL_95;
      if ( RtlCompareMemoryUlong(v42, (char *)0x10, 0) == (char *)16 )
        goto LABEL_31;
      if ( IoGetTransactionParameterBlock((int)a1) || *v9 && IoGetTransactionParameterBlock((int)v8) )
        goto LABEL_94;
      if ( *v9 )
      {
        if ( (*(_DWORD *)(v8[1] + 32) & 0x10) != 0 )
        {
          v27 = IopGetSetObjectId(v8, (int)&v38, 20, 1310952);
          if ( v27 < 0 )
            goto LABEL_95;
          v27 = IopGetSetObjectId(v8, (int)v47, 64, 590016);
          if ( v27 < 0 )
            goto LABEL_95;
          IopMarshalIds(_160, &v38, v47, v9);
          v25 = IopTrackLink(a1, a2, _160);
          goto LABEL_83;
        }
        v22 = IopGetVolumeId(v8, &v38);
LABEL_79:
        v27 = v22;
        if ( v22 < 0 )
          goto LABEL_95;
        v27 = IopGetSetObjectId(v8, (int)v47, 64, 590016);
        if ( v27 < 0 )
          goto LABEL_95;
        IopMarshalIds(_160, &v38, v47, v9);
        v27 = IopTrackLink(a1, a2, _160);
        if ( v27 < 0 )
          goto LABEL_95;
        v25 = IopGetSetObjectId(a1, 0, 0, 589984);
LABEL_83:
        v27 = v25;
        if ( v25 < 0 )
          goto LABEL_95;
        memmove((int)v45, (int)v40, 0x40u);
        v46[0] = v41 | 1;
        v27 = IopGetSetObjectId(v8, (int)v46, 48, 590012);
        if ( v27 >= 0 )
          goto LABEL_95;
        goto LABEL_85;
      }
      if ( IoGetTransactionParameterBlock((int)a1) || *v9 && IoGetTransactionParameterBlock((int)v8) )
      {
LABEL_94:
        v27 = -1072103335;
        goto LABEL_95;
      }
      v23 = IopSetRemoteLink(a1);
    }
    else
    {
      if ( *v9 )
      {
        if ( (*(_DWORD *)(v8[1] + 32) & 0x10) == 0 )
        {
          v14 = 0;
          v15 = IopGetSetObjectId(a1, (int)v40, 64, 589980);
          v27 = v15;
          if ( v15 == -1073741772 )
          {
LABEL_31:
            v27 = 0;
            goto LABEL_95;
          }
          if ( v15 >= 0 )
          {
            if ( RtlCompareMemoryUlong(v42, (char *)0x10, 0) == (char *)16 )
              goto LABEL_31;
            if ( !IoGetTransactionParameterBlock((int)a1) && (!*v9 || !IoGetTransactionParameterBlock((int)v8)) )
            {
              v27 = IopGetVolumeId(v8, &v38);
              if ( v27 < 0 )
                goto LABEL_95;
              v27 = IopGetVolumeId(a1, &v43);
              if ( v27 < 0 )
                goto LABEL_95;
              v27 = IopGetSetObjectId(a1, 0, 0, 589984);
              if ( v27 < 0 )
                goto LABEL_95;
              memmove((int)v47, (int)v40, 0x40u);
              memmove((int)v45, (int)v40, 0x40u);
              if ( memcmp((unsigned int)v39, (unsigned int)v44, 16) )
                v46[0] = v41 | 1;
              v16 = IopGetSetObjectId(v8, (int)v45, 64, 589976);
              v17 = v16;
              v27 = v16;
              if ( v16 == -1073741635 || v16 == -1073741771 )
              {
                v27 = IopGetSetObjectId(v8, (int)v47, 64, 590016);
                if ( v27 < 0 )
                  goto LABEL_50;
                v17 = IopGetSetObjectId(v8, (int)v46, 48, 590012);
                v27 = v17;
              }
              if ( v17 >= 0 )
              {
                v14 = 1;
                if ( memcmp((unsigned int)v39, (unsigned int)v44, 16) )
                {
                  IopMarshalIds(_160, &v38, v47, v9);
                  memmove((int)v36, (int)v40, 0x40u);
                  v37 = v41 & 0xFE;
                  v17 = IopSendMessageToTrackService(&v43, v36, _160);
                  v27 = v17;
                }
                if ( v17 >= 0 )
                  goto LABEL_95;
              }
LABEL_50:
              v18 = 0;
              if ( v14 )
              {
                if ( !memcmp((unsigned int)v47, (unsigned int)v40, 16) )
                {
                  v20 = 589984;
                  v21 = 0;
                  v19 = 0;
                }
                else
                {
                  v19 = &v48;
                  v20 = 590012;
                  v21 = 48;
                }
                v18 = IopGetSetObjectId(v8, (int)v19, v21, v20);
              }
              if ( v18 < 0 )
                goto LABEL_95;
LABEL_85:
              IopGetSetObjectId(a1, (int)v40, 64, 589976);
              goto LABEL_95;
            }
            goto LABEL_94;
          }
LABEL_95:
          if ( a6 && v29 )
            ExFreePoolWithTag(v29);
          if ( v31 )
            ObfDereferenceObject(v31);
          KeSetEvent(v34, 0, 0);
          return v27;
        }
        if ( IopGetSetObjectId(a1, (int)v40, 64, 589980) < 0
          || RtlCompareMemoryUlong(v42, (char *)0x10, 0) == (char *)16 )
        {
          goto LABEL_31;
        }
        if ( !IoGetTransactionParameterBlock((int)a1) && (!*v9 || !IoGetTransactionParameterBlock((int)v8)) )
        {
          v22 = IopGetSetObjectId(v8, (int)&v38, 20, 1310952);
          goto LABEL_79;
        }
        goto LABEL_94;
      }
      v27 = IopGetVolumeId(a1, &v43);
      if ( v27 < 0 )
        goto LABEL_95;
      v27 = IopGetSetObjectId(a1, (int)v40, 64, 589980);
      if ( v27 < 0 )
        goto LABEL_95;
      if ( RtlCompareMemoryUlong(v42, (char *)0x10, 0) == (char *)16 )
        goto LABEL_31;
      if ( IoGetTransactionParameterBlock((int)a1) || *v9 && IoGetTransactionParameterBlock((int)v8) )
        goto LABEL_94;
      memmove((int)v36, (int)v40, 0x40u);
      v37 = v41 & 0xFE;
      v23 = IopSendMessageToTrackService(&v43, v36, v9);
    }
    v27 = v23;
    goto LABEL_95;
  }
  if ( a6 )
    ExFreePoolWithTag((unsigned int)v9);
  return -1073741675;
}
