// NtNotifyChangeSession 
 
int __fastcall NtNotifyChangeSession(int a1, unsigned int a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int a8)
{
  int v8; // r10
  int v10; // r9
  int v11; // r2
  unsigned int v12; // r6
  int v13; // r5
  int v14; // r8
  int v15; // r1
  unsigned int v16; // r3
  unsigned int v17; // r10
  _DWORD *v18; // r4
  int v19; // r0
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // r0
  _DWORD *v24; // r6
  _DWORD v26[2]; // [sp+14h] [bp-164h] BYREF
  int v27; // [sp+1Ch] [bp-15Ch]
  int v28; // [sp+20h] [bp-158h]
  int v29; // [sp+24h] [bp-154h]
  unsigned int v30[2]; // [sp+28h] [bp-150h] BYREF
  _DWORD v31[10]; // [sp+30h] [bp-148h] BYREF
  _DWORD _58[78]; // [sp+58h] [bp-120h] BYREF

  _58[74] = a1;
  _58[75] = a2;
  _58[76] = a3;
  v8 = a4;
  v29 = a4;
  _58[77] = a4;
  v10 = 0;
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v28 = v11;
  v12 = a8;
  if ( a8 > 0x100 )
    return -1073741580;
  v13 = ObReferenceObjectByHandle(a1, 2, MmSessionObjectType, v11, (int)v26, 0);
  v27 = v13;
  v26[1] = v13;
  if ( v13 < 0 )
    return v13;
  v14 = v26[0];
  KeWaitForSingleObject(*(_DWORD *)(v26[0] + 16) + 8396, 0, 0, 0, 0);
  v15 = *(_DWORD *)(v14 + 16);
  v16 = *(_DWORD *)(v15 + 8392);
  if ( v16 == a2 )
  {
    *(_DWORD *)(v15 + 8392) = v16 + 1;
  }
  else if ( v16 <= a2 || v16 - a2 >= 0xFFFFFFFD )
  {
    v30[0] = -1000000;
    v30[1] = -1;
    LOWORD(v17) = 0;
    do
    {
      KeSetEvent(v15 + 8396, 0, 0);
      KeDelayExecutionThread(0, 0, v30);
      KeWaitForSingleObject(*(_DWORD *)(v14 + 16) + 8396, 0, 0, 0, 0);
      v17 = (unsigned __int16)(v17 + 1);
      v15 = *(_DWORD *)(v14 + 16);
    }
    while ( v17 <= 0xA && *(_DWORD *)(v15 + 8392) != a2 );
    *(_DWORD *)(*(_DWORD *)(v14 + 16) + 8392) = a2 + 1;
    v13 = v27;
    v10 = 0;
    v12 = a8;
    v8 = v29;
  }
  if ( !v8 )
  {
    KeSetEvent(*(_DWORD *)(v14 + 16) + 8396, 0, 0);
    ObfDereferenceObject(v14);
    return 0;
  }
  *(_DWORD *)(*(_DWORD *)(v14 + 16) + 8388) = a5;
  v18 = 0;
  if ( !v12 )
    goto LABEL_30;
  if ( v28 != 1 )
  {
    if ( v8 == 1 || v8 == 2 )
    {
      v18 = (_DWORD *)a7;
    }
    else
    {
      v22 = ExAllocatePoolWithTag(1, v12, 1850961737);
      v18 = (_DWORD *)v22;
      if ( !v22 )
      {
        v20 = 1;
        v18 = (_DWORD *)a7;
LABEL_31:
        v21 = a5;
        goto LABEL_32;
      }
      v10 = 1;
      memmove(v22, a7, v12);
    }
LABEL_30:
    v20 = 0;
    goto LABEL_31;
  }
  if ( a7 + v12 > MmUserProbeAddress || a7 + v12 < a7 )
    *(_BYTE *)MmUserProbeAddress = 0;
  v19 = ExAllocatePoolWithTag(1, v12, 1850961737);
  v18 = (_DWORD *)v19;
  if ( v19 )
  {
    v10 = 1;
    memmove(v19, a7, v12);
    v20 = 0;
  }
  else
  {
    v18 = _58;
    memmove((int)_58, a7, v12);
    v20 = 1;
  }
  v21 = a5;
LABEL_32:
  v31[4] = v8;
  v31[5] = v21;
  v31[6] = v12;
  v31[7] = v18;
  v31[8] = v14;
  if ( !v20 && v8 != 1 && v8 != 2 )
  {
    v23 = ExAllocatePoolWithTag(512, 36, 1850961737);
    v24 = (_DWORD *)v23;
    if ( v23 )
    {
      memmove(v23, (int)v31, 0x24u);
      v24[2] = IopSessionChangeWorker;
      v24[3] = v24;
      *v24 = 0;
      ExQueueWorkItem(v24, 1);
      return 0;
    }
  }
  ExNotifyCallback(IopSessionCallbackObject, (int)v31, 0);
  KeSetEvent(*(_DWORD *)(v14 + 16) + 8396, 0, 0);
  ObfDereferenceObject(v14);
  if ( v18 && v10 == 1 )
    ExFreePoolWithTag((unsigned int)v18);
  return v13;
}
