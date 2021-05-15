// MmVerifierTrimMemory 
 
int *MmVerifierTrimMemory()
{
  int *result; // r0
  int v1; // r1
  int v2; // r2
  int v3; // r3
  char v4; // r5
  int v5; // r6
  int v6; // [sp+0h] [bp-20h] BYREF
  int v7[6]; // [sp+8h] [bp-18h] BYREF

  result = KeQueryTickCount(v7);
  if ( (MmVerifierTrimFrequency & v7[0]) == 0 )
  {
    result = (int *)RtlpGetStackLimits((int)&v6, (int)v7, MmVerifierTrimFrequency, v7[0]);
    if ( result )
    {
      result = KeGetCurrentStackPointer((int)result, v1, v2, v3, v6);
      if ( (unsigned int)result - v6 > 0x8D0 )
      {
        ++dword_620DA0;
        v4 = (char)ViTrimSpaces;
        v5 = (int)ViTrimSpaces < 0;
        if ( ((unsigned __int8)ViTrimSpaces & 1) != 0 )
        {
          result = (int *)MiTrimAllSystemPagableMemory(0, (int)ViTrimSpaces < 0);
          if ( result == (int *)1 )
            ++dword_620DA4;
        }
        if ( (v4 & 2) != 0 )
        {
          result = (int *)MiTrimAllSystemPagableMemory(1, v5);
          if ( result == (int *)1 )
            ++dword_620DBC;
        }
        if ( (v4 & 4) != 0 )
        {
          result = (int *)MiTrimAllSystemPagableMemory(2, v5);
          if ( result == (int *)1 )
            ++dword_620DE4;
        }
      }
    }
  }
  return result;
}
