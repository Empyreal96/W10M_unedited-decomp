// EtwpObjectTypeRundown 
 
int __fastcall EtwpObjectTypeRundown(int a1, int a2)
{
  unsigned int *v4; // r4
  int result; // r0
  int v6; // r0
  int v7; // r6
  unsigned __int16 *v8; // r7
  unsigned int i; // r5
  int v10; // r3
  __int16 v11[4]; // [sp+10h] [bp-40h] BYREF
  int v12[14]; // [sp+18h] [bp-38h] BYREF

  v4 = 0;
  while ( 1 )
  {
    if ( v4 )
      ExFreePoolWithTag((unsigned int)v4);
    result = ExAllocatePoolWithTag(1, 1024, 1953985605);
    v4 = (unsigned int *)result;
    if ( !result )
      break;
    v6 = ZwQueryObject();
    if ( v6 != -1073741820 )
    {
      if ( v6 >= 0 )
      {
        v7 = 4389;
        if ( a2 )
          v7 = 4388;
        v11[1] = 0;
        v12[0] = (int)v11;
        v12[1] = 0;
        v12[2] = 4;
        v12[3] = 0;
        v8 = (unsigned __int16 *)(v4 + 1);
        for ( i = 0; i < *v4; v8 = (unsigned __int16 *)((char *)v8 + ((v8[1] + 3) & 0xFFFFFFFC) + 96) )
        {
          if ( i )
          {
            v11[0] = *((unsigned __int8 *)v8 + 82);
            v10 = *((_DWORD *)v8 + 1);
            v12[6] = *v8 + 2;
            v12[4] = v10;
            v12[5] = 0;
            v12[7] = 0;
            EtwpLogKernelEvent(v12, a1, 2, v7, 4200450);
          }
          ++i;
        }
      }
      return ExFreePoolWithTag((unsigned int)v4);
    }
  }
  return result;
}
