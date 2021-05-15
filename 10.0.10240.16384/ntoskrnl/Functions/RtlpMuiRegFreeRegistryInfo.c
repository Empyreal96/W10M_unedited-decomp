// RtlpMuiRegFreeRegistryInfo 
 
int __fastcall RtlpMuiRegFreeRegistryInfo(_DWORD *a1, int a2)
{
  int v3; // r7
  int v4; // r5
  unsigned int v5; // r0
  unsigned int v6; // r0
  unsigned int v7; // r0
  int v9; // r2
  int v10; // r2
  int v11; // r2
  int v12; // r2
  int v13; // r2
  int v14; // r0
  unsigned int v15; // r0
  unsigned int v16; // r0
  unsigned int v17; // r0
  unsigned int v18; // r0
  unsigned int v19; // r0
  unsigned int v20; // r0
  unsigned int v21; // r0

  v3 = 0;
  v4 = a2;
  if ( !a1 || !a2 )
    return -1073741811;
  if ( (a2 & 0x400) != 0 )
    v4 = 4095;
  if ( (v4 & 1) != 0 )
  {
    v5 = a1[5];
    if ( v5 )
    {
      if ( (*a1 & 1) != 0 )
        ExFreePoolWithTag(v5);
      a1[5] = 0;
    }
    *a1 &= 0xFFFFFFFE;
  }
  if ( (v4 & 2) != 0 )
  {
    v6 = a1[6];
    if ( v6 )
    {
      if ( (*a1 & 2) != 0 )
        ExFreePoolWithTag(v6);
      a1[6] = 0;
    }
    *a1 &= 0xFFFFFFFD;
  }
  if ( (v4 & 4) != 0 )
  {
    v7 = a1[7];
    if ( v7 )
    {
      if ( (*a1 & 4) != 0 )
        ExFreePoolWithTag(v7);
      a1[7] = 0;
    }
    *a1 &= 0xFFFFFFFB;
  }
  if ( (v4 & 8) != 0 )
  {
    if ( a1[8] )
      return sub_8180B4();
    *a1 &= 0xFFFFFFF7;
  }
  if ( (v4 & 0x10) != 0 )
  {
    v9 = a1[9];
    if ( v9 )
    {
      if ( (*a1 & 0x10) != 0 )
      {
        *(_DWORD *)(v9 + 32) &= 0xFFFFFFBF;
        v16 = a1[9];
        if ( v16 )
        {
          if ( (*(_DWORD *)(v16 + 32) & 0x40) == 0 )
            ExFreePoolWithTag(v16);
        }
      }
      a1[9] = 0;
    }
    *a1 &= 0xFFFFFFEF;
  }
  if ( (v4 & 0x20) != 0 )
  {
    v10 = a1[10];
    if ( v10 )
    {
      if ( (*a1 & 0x20) != 0 )
      {
        *(_DWORD *)(v10 + 32) &= 0xFFFFFFBF;
        v17 = a1[10];
        if ( v17 )
        {
          if ( (*(_DWORD *)(v17 + 32) & 0x40) == 0 )
            ExFreePoolWithTag(v17);
        }
      }
      a1[10] = 0;
    }
    *a1 &= 0xFFFFFFDF;
  }
  if ( (v4 & 0x40) != 0 )
  {
    v11 = a1[13];
    if ( v11 )
    {
      if ( (*a1 & 0x40) != 0 )
      {
        *(_DWORD *)(v11 + 32) &= 0xFFFFFFBF;
        v18 = a1[13];
        if ( v18 )
        {
          if ( (*(_DWORD *)(v18 + 32) & 0x40) == 0 )
            ExFreePoolWithTag(v18);
        }
      }
      a1[13] = 0;
    }
    *a1 &= 0xFFFFFFBF;
  }
  if ( (v4 & 0x80) != 0 )
  {
    v12 = a1[12];
    if ( v12 )
    {
      if ( (*a1 & 0x80) != 0 )
      {
        *(_DWORD *)(v12 + 32) &= 0xFFFFFFBF;
        v19 = a1[12];
        if ( v19 )
        {
          if ( (*(_DWORD *)(v19 + 32) & 0x40) == 0 )
            ExFreePoolWithTag(v19);
        }
      }
      a1[12] = 0;
    }
    *a1 &= 0xFFFFFF7F;
  }
  if ( (v4 & 0x200) != 0 )
  {
    v13 = a1[14];
    if ( v13 )
    {
      if ( (*a1 & 0x200) != 0 )
      {
        *(_DWORD *)(v13 + 32) &= 0xFFFFFFBF;
        v20 = a1[14];
        if ( v20 )
        {
          if ( (*(_DWORD *)(v20 + 32) & 0x40) == 0 )
            ExFreePoolWithTag(v20);
        }
      }
      a1[14] = 0;
    }
    *a1 &= 0xFFFFFDFF;
  }
  if ( (v4 & 0x800) != 0 )
  {
    v15 = a1[20];
    if ( v15 )
    {
      if ( (*a1 & 0x800) != 0 )
        ExFreePoolWithTag(v15);
      a1[20] = 0;
    }
    *a1 &= 0xFFFFF7FF;
  }
  if ( (v4 & 0xFFF) != 0 )
  {
    v14 = a1[15];
    if ( v14 )
    {
      RtlpMuiRegFreeRegistryInfo(v14, v4);
      v21 = a1[15];
      if ( v21 )
        ExFreePoolWithTag(v21);
      a1[15] = 0;
    }
  }
  return v3;
}
