// PnpHandleEnumerateHandlesAgainstDeviceObject 
 
int __fastcall PnpHandleEnumerateHandlesAgainstDeviceObject(int a1, int a2, int a3)
{
  int v4; // r6
  int i; // r0
  int v7; // r0
  unsigned int *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1
  int *v11; // r0
  int v12; // r5
  int v14[10]; // [sp+0h] [bp-28h] BYREF

  v4 = 0;
  for ( i = 0; ; i = v12 )
  {
    v11 = PsGetNextProcess(i);
    v12 = (int)v11;
    if ( !v11 )
      break;
    v7 = ObReferenceProcessHandleTable((int)v11);
    if ( v7 )
    {
      v14[1] = v12;
      v14[2] = (int)PnpCollectOpenHandlesCallBack;
      v14[0] = a1;
      v14[3] = a3;
      v4 = ExEnumHandleTable(v7, PnpHandleProcessWalkWorker, v14, 0);
      v8 = (unsigned int *)(v12 + 172);
      __pld((void *)(v12 + 172));
      v9 = *(_DWORD *)(v12 + 172) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v10 = __ldrex(v8);
      while ( v10 == v9 && __strex(v9 - 2, v8) );
      if ( v10 != v9 )
        ExfReleaseRundownProtection((unsigned __int8 *)v8);
      if ( v4 )
      {
        ObfDereferenceObjectWithTag(v12);
        return v4;
      }
    }
  }
  return v4;
}
