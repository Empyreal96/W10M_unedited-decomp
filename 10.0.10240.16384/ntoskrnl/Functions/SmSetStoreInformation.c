// SmSetStoreInformation 
 
int __fastcall SmSetStoreInformation(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r4
  int result; // r0
  int v6; // r8
  unsigned int v7; // r5
  int v8; // r6
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r3 = a4;
  v4 = (char)a4;
  LOBYTE(varg_r3) = a4;
  if ( a3 != 16 )
    return -1073741820;
  v6 = a2[1];
  v7 = a2[2];
  v8 = a2[3];
  if ( *a2 != 1 )
    return -1073741811;
  if ( !SeSinglePrivilegeCheck(
          SeProfileSingleProcessPrivilege,
          dword_922B94,
          (char)a4,
          (int)&SeProfileSingleProcessPrivilege) )
    return -1073741790;
  switch ( v6 )
  {
    case 3:
      result = SmProcessCreateRequest((int)SmGlobals, v7, v8, v4);
      break;
    case 4:
      result = SmProcessDeleteRequest(SmGlobals, v7, v8, v4);
      break;
    case 7:
      result = SmProcessEmptyRequest(SmGlobals, v7, v8, v4);
      break;
    case 9:
      result = SmcProcessCreateRequest(&unk_636CE4, v7, v8, v4);
      break;
    case 10:
      result = SmcProcessDeleteRequest(&unk_636CE4, v7, v8, v4);
      break;
    case 11:
      result = SmcProcessStoreCreateRequest(&unk_636CE4, v7, v8, v4);
      break;
    case 12:
      result = SmcProcessStoreDeleteRequest(&unk_636CE4, v7, v8, v4);
      break;
    case 17:
      result = SmProcessResizeRequest(SmGlobals, v7, v8, v4);
      break;
    case 18:
      result = SmcProcessResizeRequest(&unk_636CE4, v7, v8, v4);
      break;
    case 19:
      result = SmProcessConfigRequest(v7, v8, v4);
      break;
    case 20:
      result = SmProcessStoreMemoryPriorityRequest(v7, v8, v4);
      break;
    default:
      result = -1073741821;
      break;
  }
  return result;
}
