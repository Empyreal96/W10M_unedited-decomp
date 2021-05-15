// EtwpUpdatePerProcessTracing 
 
int __fastcall EtwpUpdatePerProcessTracing(int a1, int a2, int a3, int a4)
{
  char v5; // r7
  int result; // r0
  unsigned __int16 *v8; // r0
  char v9; // r1
  unsigned __int16 v10; // r2
  int v11; // r4
  int *v12; // r5
  int v13; // t1
  __int16 v14; // [sp+0h] [bp-20h]
  int v15; // [sp+4h] [bp-1Ch] BYREF
  int v16; // [sp+8h] [bp-18h] BYREF
  int v17; // [sp+Ch] [bp-14h]

  v15 = a2;
  v16 = a3;
  v17 = a4;
  HIBYTE(v14) = 0;
  v5 = a2;
  if ( PsIsCurrentThreadInServerSilo() )
    return -1073741727;
  v8 = EtwpGetFlagExtension(a1, 2);
  if ( v8 )
  {
    v10 = *v8;
    v16 = a3;
    v11 = (unsigned __int16)(4 * v10 - 4) >> 2;
    LOBYTE(v17) = v9 - 1;
    if ( v11 )
    {
      v12 = (int *)(v8 + 2);
      do
      {
        v13 = *v12++;
        if ( PsLookupProcessByProcessId(v13, &v15) >= 0 )
        {
          EtwpUpdateProcessTracingCallback(v15, &v16);
          ObfDereferenceObjectWithTag(v15);
        }
        --v11;
      }
      while ( v11 );
    }
  }
  LOBYTE(v14) = v5;
  result = 0;
  *(_WORD *)(2 * a3 - 27776) = v14;
  return result;
}
