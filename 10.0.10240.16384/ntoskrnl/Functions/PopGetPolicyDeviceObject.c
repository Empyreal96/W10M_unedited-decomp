// PopGetPolicyDeviceObject 
 
int __fastcall PopGetPolicyDeviceObject(_DWORD *a1, _DWORD *a2)
{
  int v3; // r5
  int v4; // r0
  _DWORD *v5; // r4
  int v6; // r0
  int result; // r0
  _DWORD *v8[13]; // [sp+24h] [bp-34h] BYREF

  v8[3] = (_DWORD *)24;
  v8[4] = 0;
  v8[5] = a1;
  v8[6] = (_DWORD *)576;
  v8[7] = 0;
  v8[8] = 0;
  v3 = 0;
  if ( ZwCreateFile() < 0 )
    goto LABEL_7;
  v4 = ObReferenceObjectByHandle(0, 0, (int)IoFileObjectType, 0, (int)v8, 0);
  v5 = v8[0];
  if ( v4 < 0 )
    goto LABEL_7;
  v6 = IoGetRelatedDeviceObject(v8[0]);
  v3 = v6;
  if ( v6 )
  {
    ObfReferenceObject(v6);
    *a2 = v5;
    v5 = 0;
  }
  if ( v5 )
    result = sub_7F1C9C();
  else
LABEL_7:
    result = v3;
  return result;
}
