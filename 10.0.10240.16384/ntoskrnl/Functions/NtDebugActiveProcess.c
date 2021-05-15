// NtDebugActiveProcess 
 
int __fastcall NtDebugActiveProcess(int a1, int a2)
{
  int v3; // r4
  int v4; // r5
  int v5; // r2
  _DWORD *v6; // r7
  unsigned int *v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r1
  int v10; // r0
  int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v15; // [sp+10h] [bp-28h] BYREF
  int v16[9]; // [sp+14h] [bp-24h] BYREF

  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v4 = ObReferenceObjectByHandleWithTag(a1, 2048, PsProcessType, v3, 1332175428, &v15, 0);
  if ( v4 >= 0 )
  {
    v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v6 = (_DWORD *)v15;
    if ( v15 == v5 || v15 == PsInitialSystemProcess )
    {
      v4 = -1073741790;
    }
    else if ( PspCheckForInvalidAccessByProtection(v3, *(_BYTE *)(v5 + 734), *(_BYTE *)(v15 + 734)) )
    {
      v4 = -1073740014;
    }
    else
    {
      v4 = ObReferenceObjectByHandle(a2, 2, DbgkDebugObjectType, v3, (int)&v15, 0);
      if ( v4 >= 0 )
      {
        v7 = v6 + 43;
        __pld(v6 + 43);
        v8 = v6[43] & 0xFFFFFFFE;
        do
          v9 = __ldrex(v7);
        while ( v9 == v8 && __strex(v8 + 2, v7) );
        __dmb(0xBu);
        if ( v9 == v8 || ExfAcquireRundownProtection(v6 + 43) )
        {
          v10 = DbgkpPostFakeProcessCreateMessages((int)v6, v15, v16);
          v11 = DbgkpSetProcessDebugObject(v6, v15, v10, v16[0]);
          __pld(v7);
          v4 = v11;
          v12 = *v7 & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v13 = __ldrex(v7);
          while ( v13 == v12 && __strex(v12 - 2, v7) );
          if ( v13 != v12 )
            ExfReleaseRundownProtection((unsigned __int8 *)v6 + 172);
        }
        else
        {
          v4 = -1073741558;
        }
        ObfDereferenceObject(v15);
      }
    }
    ObfDereferenceObjectWithTag((int)v6);
  }
  return v4;
}
