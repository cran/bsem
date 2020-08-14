## ---- setup, echo = F---------------------------------------------------------
knitr::opts_chunk$set(fig.width = 6, fig.height = 6, eval = FALSE, echo =  TRUE)

## ---- echo = FALSE------------------------------------------------------------
#  set.seed(2020)

## ---- eval = TRUE-------------------------------------------------------------
dt <- bsem::simdata(
  paths = NULL,
  exogenous = NULL
)

## ---- eval = TRUE-------------------------------------------------------------
dt$blocks

## -----------------------------------------------------------------------------
#  cfa <- bsem::sem(
#    data = dt$data,
#    blocks = dt$blocks,
#    cores = 1
#  )

## -----------------------------------------------------------------------------
#  cfa

## -----------------------------------------------------------------------------
#  plot(cfa)

## -----------------------------------------------------------------------------
#  gridExtra::grid.arrange(
#    bsem::arrayplot(cfa$mean_lambda, main = "estimates", -3,3),
#    bsem::arrayplot(dt$real$lambda, main = "lambda (scores)", -3,3)
#  )
#  
#  gridExtra::grid.arrange(
#    bsem::arrayplot(cfa$mean_alpha, main = "estimates", -3,3),
#    bsem::arrayplot(dt$real$alpha, main = "alpha (loadings)", -3,3),
#    layout_matrix = matrix(c(1, 1, 2, 2), ncol = 2)
#  )

## ---- eval = TRUE-------------------------------------------------------------
dt <- bsem::simdata()

## -----------------------------------------------------------------------------
#  sem <- bsem::sem(
#    data = dt$data,
#    blocks = dt$blocks,
#    paths = dt$paths,
#    exogenous = dt$exogenous
#  )

## -----------------------------------------------------------------------------
#  plot(sem)

## -----------------------------------------------------------------------------
#  names(cfa$posterior)
#  dim(cfa$posterior$alpha)

## -----------------------------------------------------------------------------
#  lnames <- rownames(cfa$mean_alpha)
#  
#    find <- paste0("alpha[", which(lnames %in% unlist(cfa$blocks[1:length(cfa$blocks)])), ",",
#                   rep(1:length(cfa$blocks), lengths(cfa$blocks)), "]"
#                   )
#    bayesplot::mcmc_trace(cfa$posterior$alpha[, , find]
#                          )

## -----------------------------------------------------------------------------
#  lnames <- rownames(cfa$mean_alpha)
#  
#    find <- paste0("alpha[", which(lnames %in% unlist(cfa$blocks[1:length(cfa$blocks)])), ",",
#                   rep(1:length(cfa$blocks), lengths(cfa$blocks)), "]"
#                   )
#    bayesplot::mcmc_dens(cfa$posterior$alpha[, , find]
#                          )

## -----------------------------------------------------------------------------
#  names(cfa$credint)

## -----------------------------------------------------------------------------
#  library("ggplot2")
#  library("tidybayes")

## -----------------------------------------------------------------------------
#  dt <- data.frame(
#    li = cfa$credint$alpha[, 1],
#    lu = cfa$credint$alpha[, 2],
#    m = c(cfa$mean_alpha)
#  )

## -----------------------------------------------------------------------------
#  lnames <- rownames(cfa$mean_alpha)
#  snames <- rownames(cfa$mean_lambda)

## -----------------------------------------------------------------------------
#  find <- paste0("alpha[", which(lnames %in% unlist(cfa$blocks)), ",", rep(1:length(cfa$blocks), lengths(cfa$blocks)), "]")
#  
#  dt <- dt[find, ]

## -----------------------------------------------------------------------------
#  ggplot(aes(y = find, x = m, xmin = li, xmax = lu), data = dt) +
#    geom_pointintervalh() +
#    theme_classic() +
#    labs(
#      title = paste("Latent variable", colnames(cfa$mean_alpha)[3]),
#      x = "Highest posterior density interval",
#      y = "variable"
#    )

## -----------------------------------------------------------------------------
#  library("bayesplot")

## -----------------------------------------------------------------------------
#  find <- paste0("alpha[", which(lnames %in% unlist(cfa$blocks)), ",",
#                 rep(1:length(cfa$blocks), lengths(cfa$blocks)), "]")
#  
#  dt <- dt[find, ]

## -----------------------------------------------------------------------------
#  gridExtra::grid.arrange(mcmc_areas(cfa$posterior$alpha[, , find]),
#    mcmc_intervals(cfa$posterior$alpha[, , find]),
#    layout_matrix = matrix(c(1, 1, 2, 2), ncol = 2)
#  )

## -----------------------------------------------------------------------------
#  bsem::runShiny()

