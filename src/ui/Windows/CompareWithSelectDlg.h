/*
* Copyright (c) 2003-2012 Rony Shapiro <ronys@users.sourceforge.net>.
* All rights reserved. Use of the code is allowed under the
* Artistic License 2.0 terms, as specified in the LICENSE file
* distributed with this code, or available from
* http://www.opensource.org/licenses/artistic-license-2.0.php
*/
// CompareWithSelectDlg.h
//-----------------------------------------------------------------------------

#pragma once

#include "PWDialog.h"
#include "SecString.h"
#include "CWListCtrl.h"
#include "CWTreeCtrl.h"

#include "os/UUID.h"

class CItemData;
class PWScore;

class CCompareWithSelectDlg : public CPWDialog
{
public:
  // default constructor
  CCompareWithSelectDlg(CItemData *pci, PWScore *pcore, bool bShowTree,
                        CWnd *pParent);
  virtual ~CCompareWithSelectDlg();

  pws_os::CUUID GetUUID();

  enum { IDD = IDD_COMPARE_WITH };

protected:
  virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support

  virtual BOOL OnInitDialog();
  afx_msg void OnDestroy();
  afx_msg void OnListItemSelected(NMHDR *pNotifyStruct, LRESULT *pLResult);
  afx_msg void OnTreeItemSelected(NMHDR *pNotifyStruct, LRESULT *pLResult);

  DECLARE_MESSAGE_MAP()

private:
  static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
  void InsertItemIntoGUITreeList(CItemData &ci, int iIndex);
  void OnItemSelected(NMHDR *pNotifyStruct, LRESULT *pLResult);

  CCWListCtrl m_cwItemList;
  CCWTreeCtrl m_cwItemTree;
  CImageList *m_pImageList;

  CSecString m_group;
  CSecString m_title;
  CSecString m_username;

  PWScore *m_pcore;
  CItemData *m_pci, *m_pSelected;
  bool m_bShowTree;
};
//-----------------------------------------------------------------------------
// Local variables:
// mode: c++
// End:
