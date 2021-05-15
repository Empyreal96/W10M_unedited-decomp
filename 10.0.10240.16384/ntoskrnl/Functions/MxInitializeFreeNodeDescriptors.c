// MxInitializeFreeNodeDescriptors 
 
int __fastcall MxInitializeFreeNodeDescriptors(int result, int a2)
{
  __int64 i; // r6
  unsigned int v3; // r8
  int *v4; // r4
  unsigned int v5; // r10
  int v6; // r5
  unsigned int v7; // r5
  int v8; // r3

  for ( i = *(_QWORD *)(result + 12); HIDWORD(i); HIDWORD(i) -= v3 )
  {
    v3 = MiRestrictRangeToNode(i, HIDWORD(i));
    result = MiPageToNode();
    v4 = &MxFreeDescriptor[4 * result];
    v5 = v4[1];
    if ( v3 >= v5 || v3 >= *(_DWORD *)(a2 + 4 * result) + 0x4000 )
    {
      v6 = v3 + i - 1;
      result = MxPageAlwaysHot(v6);
      if ( v5 )
      {
        if ( result != 1 )
        {
          result = MxPageAlwaysHot(v5 + *v4 - 1);
          if ( result )
            return sub_96B5B8();
        }
      }
      v4[1] = v3;
      v4[2] = v6;
      v7 = v6 & 0xFFFFFC00;
      v4[3] = v7;
      *v4 = i;
      if ( v7 >= (unsigned int)i && v7 - (unsigned int)i >= 0x400 )
        v8 = v7 - 1024;
      else
        v8 = -1;
      v4[3] = v8;
    }
    LODWORD(i) = i + v3;
  }
  return result;
}
