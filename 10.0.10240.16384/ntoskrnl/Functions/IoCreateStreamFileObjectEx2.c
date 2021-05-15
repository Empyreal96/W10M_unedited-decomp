// IoCreateStreamFileObjectEx2 
 
int __fastcall IoCreateStreamFileObjectEx2(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  __int16 v6; // r4
  _DWORD *v8; // r8
  BOOL v9; // r9
  _BYTE *v11; // r3
  int v12; // r0
  int v13; // r4
  int v14; // r0
  _DWORD *v15; // r0
  unsigned int v16; // r1
  int v17; // r6
  unsigned int v18; // r2
  unsigned int v19; // r2
  _BYTE *v20; // r0
  _BYTE *v21; // [sp+1Ch] [bp-44h] BYREF
  int v22; // [sp+20h] [bp-40h] BYREF
  _DWORD *v23; // [sp+24h] [bp-3Ch] BYREF
  int v24[14]; // [sp+28h] [bp-38h] BYREF

  v6 = *(_WORD *)(a1 + 2);
  v8 = a3;
  v22 = 0;
  v9 = (v6 & 2) == 0;
  *a4 = 0;
  if ( a5 )
    *a5 = 0;
  if ( *(_WORD *)a1 != 8 )
    return sub_7F6B30();
  if ( a5 && (v6 & 2) != 0 )
  {
    if ( (*(_WORD *)(a1 + 2) & 1) != 0 )
      RtlRaiseStatus(-1073741811);
    return -1073741811;
  }
  if ( a2 )
  {
    v8 = *(_DWORD **)(a2 + 4);
  }
  else if ( !a3 )
  {
    if ( (*(_WORD *)(a1 + 2) & 1) != 0 )
      RtlRaiseStatus(-1073741811);
    return -1073741811;
  }
  IopIncrementDeviceObjectRefCount((int)v8, 1);
  v24[0] = 24;
  v24[1] = 0;
  v24[3] = 512;
  v24[2] = 0;
  v24[4] = 0;
  v24[5] = 0;
  v13 = ObCreateObjectEx(0, IoFileObjectType, v24, 0);
  if ( v13 >= 0 )
  {
    memset(v21, 0, 128);
    *(_WORD *)v21 = 5;
    *((_WORD *)v21 + 1) = 128;
    *((_DWORD *)v21 + 1) = v8;
    *((_DWORD *)v21 + 11) = 256;
    KeInitializeEvent((int)(v21 + 92), 1, 0);
    *((_DWORD *)v21 + 28) = 0;
    v11 = v21 + 116;
    *((_DWORD *)v21 + 29) = v21 + 116;
    *((_DWORD *)v11 + 1) = v11;
    if ( v9 )
    {
      v12 = ObInsertObject(v21, 0, 1, 1, &v21, &v22);
      v13 = v12;
      if ( v12 < 0 )
      {
        if ( (*(_WORD *)(a1 + 2) & 1) != 0 )
          RtlRaiseStatus(v12);
        return v13;
      }
    }
    else
    {
      v15 = (_DWORD *)*((_DWORD *)v21 - 2);
      v16 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v17 = *(_DWORD *)(v16 + 2848);
      v18 = *(unsigned __int16 *)(v17 + 8);
      ++*(_DWORD *)(v17 + 20);
      if ( *(unsigned __int16 *)(v17 + 4) < v18
        || (++*(_DWORD *)(v17 + 24),
            v17 = *(_DWORD *)(v16 + 2852),
            v19 = *(unsigned __int16 *)(v17 + 8),
            ++*(_DWORD *)(v17 + 20),
            *(unsigned __int16 *)(v17 + 4) < v19) )
      {
        RtlpInterlockedPushEntrySList((unsigned __int64 *)v17, v15);
      }
      else
      {
        ++*(_DWORD *)(v17 + 24);
        (*(void (__fastcall **)(_DWORD *))(v17 + 44))(v15);
      }
      *((_DWORD *)v21 - 2) = 0;
    }
    *((_DWORD *)v21 + 11) |= 0x40000u;
    v14 = v8[9];
    if ( v14 )
      IopIncrementVpbRefCount(v14, 1);
    if ( v9 )
    {
      if ( a5 )
      {
        v20 = v21;
        *a5 = v22;
        ObfDereferenceObject((int)v20);
      }
      else
      {
        ObCloseHandle(v22);
      }
    }
    if ( *(_DWORD *)(a1 + 4) )
    {
      v13 = IopGetSetSpecificExtension((int)v21, 1, 16, 1, (int *)&v23, 0);
      if ( v13 < 0 )
      {
        if ( a5 )
        {
          ObCloseHandle(*a5);
          *a5 = 0;
        }
        else
        {
          ObfDereferenceObject((int)v21);
        }
        if ( (*(_WORD *)(a1 + 2) & 1) != 0 )
          RtlRaiseStatus(v13);
        return v13;
      }
      *v23 = *(_DWORD *)(a1 + 4);
    }
    *a4 = v21;
  }
  else
  {
    IopDecrementDeviceObjectRef(v8, 0, 0);
    if ( (*(_WORD *)(a1 + 2) & 1) != 0 )
      RtlRaiseStatus(v13);
  }
  return v13;
}
