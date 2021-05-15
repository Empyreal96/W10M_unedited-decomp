// IoWMIDeviceObjectToInstanceName 
 
int __fastcall IoWMIDeviceObjectToInstanceName(int a1, int a2, int a3)
{
  int v5; // r7
  int v6; // r4
  int v7; // r1
  _WORD *v8; // r0
  int v9; // r5
  int v11; // [sp+8h] [bp-20h] BYREF
  _DWORD v12[6]; // [sp+10h] [bp-18h] BYREF

  v5 = IoGetDeviceAttachmentBaseRef(a2);
  v6 = WmipGetGuidObjectInstanceInfo(a1, v5, v12, &v11);
  if ( v6 >= 0 )
  {
    v7 = (unsigned __int16)(LOWORD(v12[0]) + 32);
    *(_WORD *)(a3 + 2) = LOWORD(v12[0]) + 32;
    v8 = (_WORD *)ExAllocatePoolWithTag(1, v7, 1231646039);
    v9 = v12[1];
    *(_DWORD *)(a3 + 4) = v8;
    if ( v8 )
    {
      RtlStringCbPrintfW(v8, *(unsigned __int16 *)(a3 + 2), (int)L"%ws_%d", v9);
      *(_WORD *)a3 = 2 * wcslen(*(unsigned __int16 **)(a3 + 4));
      v6 = 0;
    }
    else
    {
      v6 = -1073741670;
    }
    if ( v9 )
      RtlFreeAnsiString(v12);
  }
  ObfDereferenceObject(v5);
  return v6;
}
