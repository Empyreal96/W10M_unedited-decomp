// IopAllocateBackpocketIrp 
 
int __fastcall IopAllocateBackpocketIrp(int a1, char a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r4
  bool v7; // zf
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r1
  unsigned int v12; // r1
  int v13; // r3
  int v16; // [sp+8h] [bp-20h] BYREF
  int v17; // [sp+Ch] [bp-1Ch]
  int vars4; // [sp+2Ch] [bp+4h]

  v16 = a3;
  v17 = a4;
  v4 = a2;
  if ( a2 > byte_631964 )
    return 0;
  v7 = a3 == 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !v7 )
  {
    if ( dword_631930 != v8 )
    {
      v16 = -300000000;
      v17 = -1;
      __dmb(0xBu);
      do
        v9 = __ldrex((unsigned int *)&dword_63192C);
      while ( __strex(1u, (unsigned int *)&dword_63192C) );
      __dmb(0xBu);
      if ( v9 == 1 )
      {
        do
        {
          if ( KeWaitForSingleObject((unsigned int)&byte_631934, 0, 0, 0, &v16) == 258 )
          {
            v6 = pIoAllocateIrp(a1, v4, 0, vars4);
            if ( v6 )
              return v6;
          }
          __dmb(0xBu);
          do
            v10 = __ldrex((unsigned int *)&dword_63192C);
          while ( __strex(1u, (unsigned int *)&dword_63192C) );
          __dmb(0xBu);
        }
        while ( v10 == 1 );
      }
      v6 = dword_631928;
      IoInitializeIrp(dword_631928, 40 * v4 + 152, v4 + 1);
      *(_BYTE *)(v6 + 39) = 33;
      dword_631930 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
LABEL_30:
      --*(_BYTE *)(v6 + 35);
      --*(_BYTE *)(v6 + 34);
      v13 = *(_DWORD *)(v6 + 96) - 40;
      *(_DWORD *)(v6 + 96) = v13;
      *(_DWORD *)(v6 + 104) = v13;
      if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
        IopInitActivityIdIrp(v6);
      return v6;
    }
    v6 = dword_631960;
    if ( !dword_631960 || (dword_631960 = *(_DWORD *)dword_631960, !v6) )
      KeBugCheckEx(286, 0, 0, 0, 0);
LABEL_29:
    IoInitializeIrp(v6, 40 * a2 + 152, a2 + 1);
    *(_BYTE *)(v6 + 39) = 33;
    goto LABEL_30;
  }
  if ( dword_63194C == v8 )
  {
    v6 = dword_631960;
    if ( !dword_631960 )
      return 0;
    dword_631960 = *(_DWORD *)dword_631960;
    if ( !v6 )
      return 0;
    goto LABEL_29;
  }
  v16 = -300000000;
  v17 = -1;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&dword_631948);
  while ( __strex(1u, (unsigned int *)&dword_631948) );
  __dmb(0xBu);
  if ( v11 != 1 )
  {
LABEL_26:
    v6 = dword_631944;
    IoInitializeIrp(dword_631944, 40 * v4 + 152, v4 + 1);
    *(_BYTE *)(v6 + 39) = 33;
    dword_63194C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    goto LABEL_30;
  }
  while ( 1 )
  {
    if ( KeWaitForSingleObject((unsigned int)&byte_631950, 0, 0, 0, &v16) == 258 )
    {
      v6 = pIoAllocateIrp(a1, v4, 0, vars4);
      if ( v6 )
        return v6;
    }
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&dword_631948);
    while ( __strex(1u, (unsigned int *)&dword_631948) );
    __dmb(0xBu);
    if ( v12 != 1 )
      goto LABEL_26;
  }
}
