// SdbpInitializeMatchers 
 
_DWORD *__fastcall SdbpInitializeMatchers(_DWORD *result)
{
  int v1; // r3
  int (*v2)(int); // r3

  result[106] = 28680;
  result[107] = SdbpCheckMatchingFiles;
  result[108] = 0;
  result[109] = 28722;
  result[110] = SdbpCheckMatchingRegistry;
  result[111] = 0;
  result[112] = 28723;
  result[113] = SdbpCheckMatchingText;
  result[114] = 0;
  result[115] = 28702;
  result[116] = SdbpCheckMatchingDevice;
  result[117] = 0;
  result[118] = 28727;
  result[119] = SdbpMatchOne;
  result[120] = 0;
  result[121] = 16417;
  result[123] = 0;
  v1 = result[1];
  if ( v1 && (*(_DWORD *)(v1 + 1328) & 2) != 0 )
    v2 = SdbpCheckRuntimePlatformV2;
  else
    v2 = SdbpCheckRuntimePlatform;
  result[122] = v2;
  result[124] = 28726;
  result[125] = SdbpCheckPackageAttributes;
  result[126] = 0;
  return result;
}
