/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "hermes/IRGen/IRGen.h"

#include "ESTreeIRGen.h"

#include "hermes/Parser/JSParser.h"
#include "hermes/Support/SimpleDiagHandler.h"

namespace hermes {

using namespace hermes::irgen;
using llvh::dbgs;

void generateIRFromESTree(ESTree::NodePtr node, Module *M) {
  // Generate IR into the module M.
  ESTreeIRGen generator(node, M);
  generator.doIt();
  LLVM_DEBUG(dbgs() << "Finished IRGen.\n");
}

void generateIRForCJSModule(
    sema::SemContext &semContext,
    ESTree::FunctionExpressionNode *node,
    uint32_t segmentID,
    uint32_t id,
    llvh::StringRef filename,
    Module *M) {
  // Generate IR into the module M.
  ESTreeIRGen generator(node, M);
  return generator.doCJSModule(semContext, segmentID, id, filename);
}

} // namespace hermes
