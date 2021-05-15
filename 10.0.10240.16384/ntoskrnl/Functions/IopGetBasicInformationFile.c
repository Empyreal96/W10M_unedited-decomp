// IopGetBasicInformationFile 
 
int __fastcall IopGetBasicInformationFile(_DWORD *a1, int a2)
{
  int v4; // r7
  int v5; // r3
  int (__fastcall *v6)(_DWORD *, bool, int, int *, int); // r5
  int result; // r0
  int v8; // [sp+8h] [bp-28h] BYREF
  int v9[8]; // [sp+10h] [bp-20h] BYREF

  v4 = IoGetRelatedDeviceObject(a1);
  v5 = *(_DWORD *)(*(_DWORD *)(v4 + 8) + 40);
  if ( !v5 )
    goto LABEL_7;
  v6 = *(int (__fastcall **)(_DWORD *, bool, int, int *, int))(v5 + 16);
  if ( !v6 )
    goto LABEL_7;
  if ( (MmVerifierData & 0x10) != 0 )
    return sub_806E00();
  if ( v6(a1, (a1[11] & 2) != 0, a2, v9, v4) )
    result = v9[0];
  else
LABEL_7:
    result = IopGetFileInformation(a1, 40, 4, a2, &v8);
  return result;
}
