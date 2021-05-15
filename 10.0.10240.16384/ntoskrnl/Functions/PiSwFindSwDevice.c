// PiSwFindSwDevice 
 
int __fastcall PiSwFindSwDevice(int a1)
{
  _WORD *v1; // r0
  int *v2; // r0
  int result; // r0
  char *v4; // [sp+0h] [bp-210h] BYREF
  char v5; // [sp+8h] [bp-208h] BYREF
  char *v6; // [sp+10h] [bp-200h]
  _WORD *v7; // [sp+14h] [bp-1FCh]
  char v8[10]; // [sp+78h] [bp-198h] BYREF
  __int16 v9[199]; // [sp+82h] [bp-18Eh] BYREF

  v4 = &v5;
  if ( !wcsnicmp(a1, L"SWD\\", 4)
    && RtlStringCbCopyW((int)v8, 0x190u) >= 0
    && (v6 = v8, (v1 = wcschr(v9, 92)) != 0)
    && (*v1 = 0, v7 = v1 + 1,
                 (v2 = (int *)RtlLookupElementGenericTableAvl((int)&PiSwDeviceInstanceTable, (int)&v4)) != 0) )
  {
    result = *v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
